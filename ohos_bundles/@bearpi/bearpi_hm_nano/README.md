# BearPi-HM_Nano
## 一、简介
BearPi-HM_Nano开发板是一块专门为HarmonyOS设计的HarmonyOS开发板，板载高度集成的2.4GHz WLAN SoC芯片Hi3861，并板载NFC电路及标准的E53接口，标准的E53接口可扩展智能加湿器、智能台灯、智能安防、智能烟感等案例。

BearPi-HM Nano提供多个案例，案例以A、B、C、D进行不同类别进行分级，方便初学者由浅入深逐步学习。您拿到工程后经过简单的编程和下载即可看到实验现象。下面依次对A/B/C/D类进行介绍：

* `A1 - A99`：内核类
* `B1 - B99`：基础外设类
* `C1 - C99`：E53传感器类
* `D1 - D99`：物联网类

例程列表如下所示：

| 编号 | 类别   | 例程名           | 说明                                                         |
| ---- | ------ | ---------------- | ------------------------------------------------------------ |
| A1   | 内核   | thread           |   [任务交替打印](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A1_kernal_thread/README.md)  |
| A2   | 内核   | timer            |  [定时器  ](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A2_kernel_timer/README.md)                                                      |
| A3   | 内核   | event            |   [事件](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A3_kernel_event/README.md)|
| A4   | 内核   | mutex            |   [互斥锁](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A4_kernel_mutex/README.md)|
| A5   | 内核   | semp             |   [信号量](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A5_kernel_semaphore/README.md)|
| A6   | 内核   | message           |    [消息队列](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/A6_kernel_message/README.md)|
| B1   | 基础   | led_blink        |   [红色 LED 不间断烁](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B1_basic_led_blink/README.md)|
| B2   | 基础   | button           |   [按键控制LED灯亮灭](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B2_basic_button/README.md)|
| B3   | 基础   | pwm_led          |   [红色 LED 呼吸灯](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B3_basic_pwm_led/README.md)|
| B4   | 基础   | adc_mq2          |   [ADC读取电压](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B4_basic_adc/README.md)|
| B5   | 基础   | i2c_bh1750       |   [I2C读取NFC标签](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B5_basic_i2c_nfc/README.md)|
| B6   | 基础   | basic_uart       |   [UART自发自收](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/B6_basic_uart/README.md)|
| C1   | E53传感器   | e53_sf1_example        |       [驱动烟雾传感器 MQ2](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/C1_e53_sf1_mq2/README.md)|
| C2   | E53传感器   | e53_ia1_example              |   [驱动温湿度传感器 SHT30](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/C2_e53_ia1_temp_humi_pls/README.md)|
| C3   | E53传感器   | e53_sc1_example             |   [驱动光强传感器 BH1750](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/C3_e53_sc1_pls/README.md)|
| C4   | E53传感器   | e53_sc2_example        |   [驱动 6 轴陀螺仪 MPU6050](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/C4_e53_sc2_axis/README.md)|
| C5   | E53传感器   | e53_is1_example              |   [驱动人体红外传感器](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/C5_e53_is1_infrared/README.md)|
| D1   | 物联网 | iot_wifi_ap        |   [Wifi热点创建](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D1_iot_wifi_ap/README.md)|
| D2   | 物联网 | iot_wifi_sta_connect    |   [Wifi联网](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D2_iot_wifi_sta_connect/README.md)|
| D3   | 物联网 | udp_client       |   [使用 Socket 实现 UDP 客户端](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D3_iot_udp_client/README.md)|
| D4   | 物联网 | tcp_server       |   [使用 Socket 实现 TCP 服务端](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D4_iot_tcp_server/README.md)|
| D5   | 物联网 | iot_mqtt             |   [使用 Paho-MQTT 软件包实现 MQTT 协议通信](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D5_iot_mqtt/README.md)|
| D6   | 物联网 | iot_cloud_oc_sample     |  [接入华为IoT 云平台](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D6_iot_cloud_oc/README.md)|
| D7   | 物联网 | iot_cloud_oc_smoke         |   [基于华为IoT平台的智慧烟感案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D7_iot_cloud_oc_smoke/README.md)|  
| D8   | 物联网 | iot_cloud_oc_light         |   [基于华为IoT平台的智慧路灯案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D8_iot_cloud_oc_light/README.md)|    
| D9   | 物联网 | iot_cloud_oc_manhole_cover         |   [基于华为IoT平台的智慧井盖案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D9_iot_cloud_oc_manhole_cover/README.md)|  
| D10   | 物联网 | iot_cloud_oc_infrared         |   [基于华为IoT平台的智慧人体感应案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D10_iot_cloud_oc_infrared/README.md)|  
| D11   | 物联网 | iot_cloud_oc_agriculture         |   [基于华为IoT平台的智慧农业案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D11_iot_cloud_oc_agriculture/README.md)| 
| D12   | 物联网 | iot_cloud_oc_gps         |   [基于华为IoT平台的智慧物流案例](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/app/D12_iot_cloud_oc_gps/README.md)|    
 

## 二、快速上手

### 1、硬件准备
|硬件名称|	数量|
| ---- | ------ |
|BearPi-HM Nano 开发套件|	1|

### 2、Linux编译服务器基础环境准备
开发基础环境由windows 工作台和Linux 编译服务器组成。windows 工作台可以通过samba 服务或ssh 方式访问Linux编译服务器。其中windows 工作台用来烧录和代码编辑，Linux编译服务器用来编译OpenHarmony代码，为了简化步骤，Linux编译服务器推荐安装Ubuntu20.04。

#### 安装和配置Python

打开Linux终端。

输入如下命令，查看python版本号，需要使用python3.7以上版本,否则参考 系统基础环境搭建。

```
python3 --version
```
安装并升级Python包管理工具（pip3）。
```
sudo apt-get install python3-setuptools python3-pip -y
sudo pip3 install --upgrade pip
```
### 3、Hi3861开发环境准备
在Linux编译服务器上搭建好基础开发环境后，需要安装OpenHarmony 编译Hi3861 平台特有的开发环境。

#### 安装编译依赖基础软件
```
sudo apt-get install -y build-essential gcc g++ make zlib* libffi-dev
```

#### 安装Scons

打开Linux 终端。

运行如下命令，安装Scons安装包。
```
python3 -m pip install scons
```

运行如下命令，查看是否安装成功。如果安装成功，可查询到版本号。
```
scons -v
```
### 4、组件下载&编译准备
#### 1.创建一个新的发行版继承自本发行版
```
hpm init -t dist
```
#### 2.下载安装发行版案例
```
hpm i @bearpi/bearpi_hm_nano
```

### 5、编译&烧录

#### 1、修改BUILD.gn 编译对应案例

打开applications\BearPi\BearPi-HM_Nano\sample\BUILD.gn中应用案例的屏蔽开关，即可编译对应案例
```
#"A1_kernal_thread:thread_example",
#"A2_kernel_timer:timer_example",
#"A3_kernel_event:event_example",
#"A4_kernel_mutex:mutex_example",
#"A5_kernel_semaphore:semaphore_example",
#"A6_kernel_message:message_example",

#"B1_basic_led_blink:led_example",
"B2_basic_button:button_example",
#"B3_basic_pwm_led:pwm_example",
#"B4_basic_adc:adc_example",
#"B5_basic_i2c_nfc:i2c_example",
#"B6_basic_uart:uart_example",

#"C1_e53_sf1_mq2:e53_sf1_example",
#"C2_e53_ia1_temp_humi_pls:e53_ia1_example",
#"C3_e53_sc1_pls:e53_sc1_example",
#"C4_e53_sc2_axis:e53_sc2_example",
#"C5_e53_is1_infrared:e53_is1_example",

#"D1_iot_wifi_ap:wifi_ap",
#"D2_iot_wifi_sta_connect:wifi_sta_connect",        
#"D3_iot_udp_client:udp_client",
#"D4_iot_tcp_server:tcp_server",
#"D5_iot_mqtt:iot_mqtt",        
#"D6_iot_cloud_oc:oc_mqtt",
#"D7_iot_cloud_onenet:onenet_mqtt",
#"D8_iot_cloud_oc_smoke:cloud_oc_smoke",
#"D9_iot_cloud_oc_light:cloud_oc_light",
#"D10_iot_cloud_oc_manhole_cover:cloud_oc_manhole_cover",
#"D11_iot_cloud_oc_infrared:cloud_oc_infrared",
#"D12_iot_cloud_oc_agriculture:cloud_oc_agriculture",
#"D13_iot_cloud_oc_gps:cloud_oc_gps",
```



#### 2.编译
```
hpm dist

#回车，等待屏幕出现：BUILD SUCCESS字样，说明编译成功
```
#### 3.烧录
请参考[《BearPi-HM_Nano开发板编译调试》](https://gitee.com/openharmony/device_board_bearpi/blob/master/bearpi_hm_nano/docs/quick-start/BearPi-HM_Nano%E5%BC%80%E5%8F%91%E6%9D%BF%E7%BC%96%E8%AF%91%E8%B0%83%E8%AF%95.md)之烧录程序章节教程。
### 6.调试

案例调试可以参考对应案例代码下的README.md文件。

例如：

任务交替打印实验可参考
applications\BearPi\BearPi-HM_Nano\sample\A1_kernal_thread路径下的README.md文件

