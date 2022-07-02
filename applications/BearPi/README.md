# BearPi-HM_Nano介绍

BearPi-HM_Nano开发板是一块专门为鸿蒙OS设计的鸿蒙OS开发板，板载高度集成的2.4GHz WLAN SoC芯片Hi3861，并板载NFC电路及标准的E53接口，标准的E53接口可扩展智能加湿器、智能台灯、智能安防、智能烟感等案例

### 购买地址 [点击购买](https://item.taobao.com/item.htm?id=633296694816)
### 视频教程地址 [点击观看](https://space.bilibili.com/470797387/channel/detail?cid=161760)

![BearPi-HM_Nano](https://www.holdiot.com/upload/202012/1606982774975847.png)



# 开发板规格<a name="section169054431017"></a>

**表 1**  BearPi-HM_Nano开发板规格清单

<a name="t672b053e2ac94cbdb5244857fed4764e"></a>
<table><thead align="left"><tr id="r54b3810e43d24e1887c1d6a41394996b"><th class="cellrowborder" valign="top" width="18.02%" id="mcps1.2.3.1.1"><p id="a2b235e9ed55f4338886788f140e648a0"><a name="a2b235e9ed55f4338886788f140e648a0"></a><a name="a2b235e9ed55f4338886788f140e648a0"></a>规格类型</p>
</th>
<th class="cellrowborder" valign="top" width="81.98%" id="mcps1.2.3.1.2"><p id="a95c4ba2e404f4a45b65984746aaa56ab"><a name="a95c4ba2e404f4a45b65984746aaa56ab"></a><a name="a95c4ba2e404f4a45b65984746aaa56ab"></a>规格清单</p>
</th>
</tr>
</thead>
<tbody><tr id="r71f534ea66af4191b020408df5978f41"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="a0531f1bb62d5443880576cc5de23f2e6"><a name="a0531f1bb62d5443880576cc5de23f2e6"></a><a name="a0531f1bb62d5443880576cc5de23f2e6"></a>通用规格</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="u2a0d06f28d454d30818ced9a0432211b"></a><a name="u2a0d06f28d454d30818ced9a0432211b"></a><ul id="u2a0d06f28d454d30818ced9a0432211b"><li>1×1 2.4GHz频段（ch1～ch14）</li><li>PHY支持IEEE 802.11b/g/n</li><li>MAC支持IEEE802.11 d/e/h/i/k/v/w</li></ul>
<a name="u8f31d142d92147789195a18b50836d2c"></a><a name="u8f31d142d92147789195a18b50836d2c"></a><ul id="u8f31d142d92147789195a18b50836d2c"><li>内置PA和LNA，集成TX/RX Switch、Balun等</li><li>支持STA和AP形态，作为AP时最大支持6 个STA接入</li><li>支持WFA WPA/WPA2 personal、WPS2.0</li><li>支持与BT/BLE芯片共存的2/3/4 线PTA方案</li><li>电源电压输入范围：2.3V～3.6V</li></ul>
<a name="ul114549122110"></a><a name="ul114549122110"></a><ul id="ul114549122110"><li>IO电源电压支持1.8V和3.3V</li></ul>
<a name="ue044275c53b84dd29dda674e16e72823"></a><a name="ue044275c53b84dd29dda674e16e72823"></a><ul id="ue044275c53b84dd29dda674e16e72823"><li>支持RF自校准方案</li><li>低功耗：<a name="ul0879143622219"></a><a name="ul0879143622219"></a><ul id="ul0879143622219"><li>Ultra Deep Sleep模式：5μA@3.3V</li><li>DTIM1：1.5mA@3.3V</li><li>DTIM3：0.8mA@3.3V</li></ul>
</li></ul>
</td>
</tr>
<tr id="rd9b56e759af34950b6887ca1bf5bb7cf"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="a0aed3860a78a4b50bedf60699afd3996"><a name="a0aed3860a78a4b50bedf60699afd3996"></a><a name="a0aed3860a78a4b50bedf60699afd3996"></a>PHY特性</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="u6568aa052152432aa1f44372445ca634"></a><a name="u6568aa052152432aa1f44372445ca634"></a><ul id="u6568aa052152432aa1f44372445ca634"><li>支持IEEE802.11b/g/n单天线所有的数据速率</li><li>支持最大速率：72.2Mbps@HT20 MCS7</li><li>支持标准20MHz带宽和5M/10M窄带宽</li><li>支持STBC</li><li>支持Short-GI</li></ul>
</td>
</tr>
<tr id="r3563f9df9759486794952d46c5d2d03f"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="afd48a2d879dc4aada8b60bebb96523c7"><a name="afd48a2d879dc4aada8b60bebb96523c7"></a><a name="afd48a2d879dc4aada8b60bebb96523c7"></a>MAC特性</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="uca57d799e7814925a5bf1b891335bd79"></a><a name="uca57d799e7814925a5bf1b891335bd79"></a><ul id="uca57d799e7814925a5bf1b891335bd79"><li>支持A-MPDU，A-MSDU</li><li>支持Blk-ACK</li><li>支持QoS，满足不同业务服务质量需求</li></ul>
</td>
</tr>
<tr id="r3e1c86e5f6cd4df0a1b30a08fb8481a2"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="a57086ea97a1b46cdb21953bf0fc22d94"><a name="a57086ea97a1b46cdb21953bf0fc22d94"></a><a name="a57086ea97a1b46cdb21953bf0fc22d94"></a>CPU子系统</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="u612cc2cd0cfe40229263c4f506c0c69c"></a><a name="u612cc2cd0cfe40229263c4f506c0c69c"></a><ul id="u612cc2cd0cfe40229263c4f506c0c69c"><li>高性能 32bit微处理器，最大工作频率160MHz</li><li>内嵌SRAM 352KB、ROM 288KB</li><li>内嵌 2MB Flash</li></ul>
</td>
</tr>
<tr id="rae93c5236b084cd2a2c0d5c29027b40e"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="a9b14a9e95b3849278c332259d8add1b2"><a name="a9b14a9e95b3849278c332259d8add1b2"></a><a name="a9b14a9e95b3849278c332259d8add1b2"></a>外围接口</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="u7c73ebffd89e4092bd65f0d878d59b22"></a><a name="u7c73ebffd89e4092bd65f0d878d59b22"></a><ul id="u7c73ebffd89e4092bd65f0d878d59b22"><li>1个SDIO接口、2个SPI接口、2个I2C接口、3个UART接口、15个GPIO接口、7路ADC输入、6路PWM、1个I2S接口（注：上述接口通过复用实现）</li><li>外部主晶体频率40M或24M</li></ul>
</td>
</tr>
<tr id="r18810701aafe42ad8d9a7d882730c210"><td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.2.3.1.1 "><p id="ae8f47db913724e458c265e858409950b"><a name="ae8f47db913724e458c265e858409950b"></a><a name="ae8f47db913724e458c265e858409950b"></a>其他信息</p>
</td>
<td class="cellrowborder" valign="top" width="81.98%" headers="mcps1.2.3.1.2 "><a name="u25f28919a3b044c5af50f9f5f5616083"></a><a name="u25f28919a3b044c5af50f9f5f5616083"></a><ul id="u25f28919a3b044c5af50f9f5f5616083"><li>封装：QFN-32，5mm×5mm</li><li>工作温度：-40℃～+85℃</li></ul>
</td>
</tr>
</tbody>
</table>


# BearPi-HM_Nano案例介绍

BearPi-HM_Nano 提供的例程多达 24个，每个例程都有非常详细的注释，代码风格统一，按照基本例程到高级例程的方式编排，方便初学者由浅入深逐步学习。开发者拿到工程后经过简单的编译和下载即可看到实验现象。

这些例程包括四个类别：内核类、基本外设类、驱动类、物联网类。不仅包括了硬件资源的应用，更是提供了丰富的物联网领域的应用示例，帮助物联网开发者更好更快地进行开发。

例程列表如下所示：

| 编号 | 类别   | 例程名           | 说明                                                         |
| ---- | ------ | ---------------- | ------------------------------------------------------------ |
| A1   | 内核   | thread           |   任务交替打印|
| A2   | 内核   | timer            |  定时器                                                     |
| A3   | 内核   | event            |   事件]|
| A4   | 内核   | mutex            |   互斥锁|
| A5   | 内核   | semp             |   信号量|
| A6   | 内核   | message           |    消息队列|
| B1   | 基础   | led_blink        |   红色 LED 不间断烁|
| B2   | 基础   | button           |   按键控制LED灯亮灭|
| B3   | 基础   | pwm_led          |   红色 LED 呼吸灯|
| B4   | 基础   | adc_mq2          |   ADC读取电压|
| B5   | 基础   | i2c_bh1750       |   I2C读取NFC标签|
| B6   | 基础   | basic_uart       |   UART自发自收|
| C1   | E53传感器   | e53_sf1_example        |       驱动烟雾传感器 MQ2|
| C2   | E53传感器   | e53_ia1_example              |   驱动温湿度传感器 SHT30|
| C3   | E53传感器   | e53_sc1_example             |   驱动光强传感器 BH1750|
| C4   | E53传感器   | e53_sc2_example        |   驱动 6 轴陀螺仪 MPU6050|
| C5   | E53传感器   | e53_is1_example              |   驱动人体红外传感器|
| D1   | 物联网 | wifi_ap       |   Wifi热点创建|
| D2   | 物联网 | wifi_sta_connect     |   Wifi联网|
| D3   | 物联网 | udp_client       |   使用 Socket 实现 UDP 客户端|
| D4   | 物联网 | tcp_server       |   使用 Socket 实现 TCP 服务端|
| D5   | 物联网 | iot_mqtt             |   使用 Paho-MQTT 软件包实现 MQTT 协议通信|
| D6   | 物联网 | iot_cloud_oc_sample     |  接入华为IoT 云平台|
| D7   | 物联网 | iot_cloud_onenet_sample         |   接入中国移动 OneNET 云平台|

