
/*
 * Copyright (c) 2020 Nanjing Xiaoxiongpai Intelligent Technology Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ohos_init.h"
#include "cmsis_os2.h"

#include "wifi_connect.h"
#include "lwip/sockets.h"

#include "oc_mqtt.h"
#include "E53_IA1.h"

#define MSGQUEUE_OBJECTS 16 // number of Message Queue Objects

typedef struct
{ // object data type
    char *Buf;
    uint8_t Idx;
} MSGQUEUE_OBJ_t;

MSGQUEUE_OBJ_t msg;
osMessageQueueId_t mid_MsgQueue; // message queue id

#define CLIENT_ID "62bd8aa24c7c4e3646b875b5_OilSensor_0_0_2022070106"
#define USERNAME "62bd8aa24c7c4e3646b875b5_OilSensor"
#define PASSWORD "1a78381e1d0c4f46b50063e3d37e891ad1f86f2bef18e8b590745a629fef4b4f"

typedef enum
{
    en_msg_cmd = 0,
    en_msg_report,
} en_msg_type_t;

typedef struct
{
    char *request_id;
    char *payload;
} cmd_t;

typedef struct
{
    float flow;
    float temp;
    float hum;
    float disp;
    float pres;
} report_t;

typedef struct
{
    en_msg_type_t msg_type;
    union
    {
        cmd_t cmd;
        report_t report;
    } msg;
} app_msg_t;

typedef struct
{
    int connected;
    int led;
    int motor;
} app_cb_t;
static app_cb_t g_app_cb;

////////////////////////below changed///////////////////////////

static void deal_report_msg(report_t *report)
{
    oc_mqtt_profile_service_t OilWell;
    oc_mqtt_profile_kv_t Temperature;
    oc_mqtt_profile_kv_t Humidity;
    oc_mqtt_profile_kv_t FlowRate;
    oc_mqtt_profile_kv_t Displacement;
    oc_mqtt_profile_kv_t Pressure;

    OilWell.event_time = NULL;
    OilWell.service_id = "OilWell";
    OilWell.service_property = &Temperature;
    OilWell.nxt = NULL;

    Temperature.key = "Temperature";
    Temperature.value = &report->temp;
    Temperature.type = EN_OC_MQTT_PROFILE_VALUE_FLOAT;
    Temperature.nxt = &Humidity;

    Humidity.key = "Humidity";
    Humidity.value = &report->hum;
    Humidity.type = EN_OC_MQTT_PROFILE_VALUE_FLOAT;
    Humidity.nxt = &FlowRate;

    FlowRate.key = "FlowRate";
    FlowRate.value = &report->flow;
    FlowRate.type = EN_OC_MQTT_PROFILE_VALUE_FLOAT;
    FlowRate.nxt = &Displacement;

    Displacement.key = "Displacement";
    Displacement.value=&report->disp;
    Displacement.type = EN_OC_MQTT_PROFILE_VALUE_FLOAT;
    Displacement.nxt = &Pressure;

    Pressure.key = "Pressure";
    Pressure.value = &report->pres;
    Pressure.type = EN_OC_MQTT_PROFILE_VALUE_FLOAT;
    Pressure.nxt = NULL;

    oc_mqtt_profile_propertyreport(USERNAME, &OilWell);
    return;
}

///////////////////////////above changed/////////////////////////


void oc_cmd_rsp_cb(uint8_t *recv_data, size_t recv_size, uint8_t **resp_data, size_t *resp_size)
{
    app_msg_t *app_msg;

    int ret = 0;
    app_msg = malloc(sizeof(app_msg_t));
    app_msg->msg_type = en_msg_cmd;
    app_msg->msg.cmd.payload = (char *)recv_data;

    printf("recv data is %.*s\n", recv_size, recv_data);
    ret = osMessageQueuePut(mid_MsgQueue, &app_msg, 0U, 0U);
    if (ret != 0)
    {
        free(recv_data);
    }
    *resp_data = NULL;
    *resp_size = 0;
}

///< COMMAND DEAL
#include <cJSON.h>
static void deal_cmd_msg(cmd_t *cmd)
{
    cJSON *obj_root;
    cJSON *obj_cmdname;
    cJSON *obj_paras;
    cJSON *obj_para;

    int cmdret = 1;
    oc_mqtt_profile_cmdresp_t cmdresp;
    obj_root = cJSON_Parse(cmd->payload);
    if (NULL == obj_root)
    {
        goto EXIT_JSONPARSE;
    }

    obj_cmdname = cJSON_GetObjectItem(obj_root, "command_name");
    if (NULL == obj_cmdname)
    {
        goto EXIT_CMDOBJ;
    }
    if (0 == strcmp(cJSON_GetStringValue(obj_cmdname), "Agriculture_Control_light"))
    {
        obj_paras = cJSON_GetObjectItem(obj_root, "paras");
        if (NULL == obj_paras)
        {
            goto EXIT_OBJPARAS;
        }
        obj_para = cJSON_GetObjectItem(obj_paras, "Light");
        if (NULL == obj_para)
        {
            goto EXIT_OBJPARA;
        }
        ///< operate the LED here
        if (0 == strcmp(cJSON_GetStringValue(obj_para), "ON"))
        {
            g_app_cb.led = 1;
            Light_StatusSet(ON);
            printf("Light On!");
        }
        else
        {
            g_app_cb.led = 0;
            Light_StatusSet(OFF);
            printf("Light Off!");
        }
        cmdret = 0;
    }
    else if (0 == strcmp(cJSON_GetStringValue(obj_cmdname), "Agriculture_Control_Motor"))
    {
        obj_paras = cJSON_GetObjectItem(obj_root, "Paras");
        if (NULL == obj_paras)
        {
            goto EXIT_OBJPARAS;
        }
        obj_para = cJSON_GetObjectItem(obj_paras, "Motor");
        if (NULL == obj_para)
        {
            goto EXIT_OBJPARA;
        }
        ///< operate the Motor here
        if (0 == strcmp(cJSON_GetStringValue(obj_para), "ON"))
        {
            g_app_cb.motor = 1;
            Motor_StatusSet(ON);
            printf("Motor On!");
        }
        else
        {
            g_app_cb.motor = 0;
            Motor_StatusSet(OFF);
            printf("Motor Off!");
        }
        cmdret = 0;
    }

EXIT_OBJPARA:
EXIT_OBJPARAS:
EXIT_CMDOBJ:
    cJSON_Delete(obj_root);
EXIT_JSONPARSE:
    ///< do the response
    cmdresp.paras = NULL;
    cmdresp.request_id = cmd->request_id;
    cmdresp.ret_code = cmdret;
    cmdresp.ret_name = NULL;
    (void)oc_mqtt_profile_cmdresp(NULL, &cmdresp);
    return;
}

static int task_main_entry(void)
{
    app_msg_t *app_msg;

    uint32_t ret = WifiConnect("UPC-IoT", "");//////////////////////////////need to change

    device_info_init(CLIENT_ID, USERNAME, PASSWORD);
    oc_mqtt_init();
    oc_set_cmd_rsp_cb(oc_cmd_rsp_cb);

    while (1)
    {
        app_msg = NULL;
        (void)osMessageQueueGet(mid_MsgQueue, (void **)&app_msg, NULL, 0U);
        if (NULL != app_msg)
        {
            switch (app_msg->msg_type)
            {
            case en_msg_cmd:
                deal_cmd_msg(&app_msg->msg.cmd);
                break;
            case en_msg_report:
                deal_report_msg(&app_msg->msg.report);
                break;
            default:
                break;
            }
            free(app_msg);
        }
    }
    return 0;
}


//////////////////below changed////////////////////

static int task_sensor_entry(void)
{
    app_msg_t *app_msg;
    E53_IA1_Data_TypeDef data;
    E53_IA1_Init();///////////////////////////need to change
    while (1)
    {
        E53_IA1_Read_Data(&data);
        app_msg = malloc(sizeof(app_msg_t));
        //printf("SENSOR:lum:%.2f temp:%.2f hum:%.2f\r\n", data.Lux, data.Temperature, data.Humidity);
        print("SensorData: Temp: %.2f Hum: %.2f Flow: %.2f Disp: %.2f Press: %.2f\n\r",data);
        if (NULL != app_msg)
        {
            app_msg->msg_type = en_msg_report;
            app_msg->msg.report.hum = (float)data.Humidity;
            app_msg->msg.report.disp = (float)data.Displacement;
            app_msg->msg.report.temp = (float)data.Temperature;
            app_msg->msg.report.flow=(float)data.FlowRate;
            app_msg->msg.report.pres=(float)data.Pressure;
            if (0 != osMessageQueuePut(mid_MsgQueue, &app_msg, 0U, 0U))
            {
                free(app_msg);
            }
        }
        sleep(3);
    }
    return 0;
}

//////////////////////above changed////////////////////

static void OC_Demo(void)
{
    mid_MsgQueue = osMessageQueueNew(MSGQUEUE_OBJECTS, 10, NULL);
    if (mid_MsgQueue == NULL)
    {
        printf("Falied to create Message Queue!\n");
    }

    osThreadAttr_t attr;

    attr.name = "task_main_entry";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 10240;
    attr.priority = 24;

    if (osThreadNew((osThreadFunc_t)task_main_entry, NULL, &attr) == NULL)
    {
        printf("Falied to create task_main_entry!\n");
    }
    attr.stack_size = 2048;
    attr.priority = 25;
    attr.name = "task_sensor_entry";
    if (osThreadNew((osThreadFunc_t)task_sensor_entry, NULL, &attr) == NULL)
    {
        printf("Falied to create task_sensor_entry!\n");
    }
}

APP_FEATURE_INIT(OC_Demo);