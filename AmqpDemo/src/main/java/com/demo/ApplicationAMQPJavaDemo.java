package com.demo;

import com.alibaba.fastjson2.JSON;
import org.apache.qpid.jms.JmsConnection;
import org.apache.qpid.jms.JmsConnectionFactory;
import org.apache.qpid.jms.JmsConnectionListener;
import org.apache.qpid.jms.message.JmsInboundMessageDispatch;
import org.apache.qpid.jms.transports.TransportOptions;
import org.apache.qpid.jms.transports.TransportSupport;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.net.URI;
import java.sql.DriverManager;
import java.util.Hashtable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import org.apache.commons.io.FileUtils;
import org.springframework.util.ResourceUtils;


public class ApplicationAMQPJavaDemo {
    //异步线程池，参数可以根据业务特点作调整，也可以用其他异步方式来处理。
    private final static ExecutorService executorService = new ThreadPoolExecutor(
            Runtime.getRuntime().availableProcessors(), Runtime.getRuntime().availableProcessors() * 2,
            60, TimeUnit.SECONDS, new LinkedBlockingQueue<>(5000));

    //todo change the url
    private static final String URI = "jdbc:mysql://127.0.0.1/music?"
            + "user=root&password=123456&useUnicode=true&characterEncoding=UTF-8";

    private static final String DRIVER = "com.mysql.jdbc.Driver";

    public static Connection connectDB() throws Exception {
        //1、加载数据库驱动
        Class.forName(DRIVER);
        //2、获取数据库连接
        Connection conn = (Connection) DriverManager.getConnection(URI);

        return conn;
    }


    public static void main(String[] args) throws Exception {
        //连接凭证接入键值。
        String accessKey = "kcFavoJ0";
        long timeStamp = System.currentTimeMillis();
        //UserName组装方法，请参见文档：AMQP客户端接入说明。
        String userName = "accessKey=" + accessKey + "|timestamp=" + timeStamp;
        //连接凭证接入码。
        String password = "SjKMalZqSgdHzuCZBwd4h2OBgjur4Ect";
        //按照qpid-jms的规范，组装连接URL。
        String baseUrl = "2fbb38c30c.iot-amqps.cn-north-4.myhuaweicloud.com";
        String connectionUrl = "amqps://" + baseUrl + ":5671?amqp.vhost=default&amqp.idleTimeout=8000&amqp.saslMechanisms=PLAIN";
        Hashtable<String, String> hashtable = new Hashtable<>();
        hashtable.put("connectionfactory.HwConnectionURL", connectionUrl);
        //队列名，可以使用默认队列DefaultQueue
        String queueName = "DefaultQueue";
        hashtable.put("queue.HwQueueName", queueName);
        hashtable
                .put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.qpid.jms.jndi.JmsInitialContextFactory");
        Context context = new InitialContext(hashtable);
        JmsConnectionFactory cf = (JmsConnectionFactory) context.lookup("HwConnectionURL");
        //同一个链接可创建多个queue,与前面queue.HwQueueName作好配对就行
        Destination queue = (Destination) context.lookup("HwQueueName");

        //信任服务端
        TransportOptions to = new TransportOptions();
        to.setTrustAll(true);
        cf.setSslContext(TransportSupport.createJdkSslContext(to));

        // 创建连接
        Connection connection = cf.createConnection(userName, password);
        ((JmsConnection) connection).addConnectionListener(myJmsConnectionListener);
        // 创建 Session
        // Session.CLIENT_ACKNOWLEDGE: 收到消息后，需要手动调用message.acknowledge()。
        // Session.AUTO_ACKNOWLEDGE: SDK自动ACK（推荐）。
        Session session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
        connection.start();
        // 创建 Receiver Link
        MessageConsumer consumer = session.createConsumer(queue);
        //处理消息有两种方式
        // 1，主动拉数据（推荐），参照receiveMessage(consumer)
        // 2, 添加监听，参照consumer.setMessageListener(messageListener), 服务端主动推数据给客户端，但得考虑接受的数据速率是客户能力能够承受住的
        receiveMessage(consumer);
        // consumer.setMessageListener(messageListener);
    }

    private static void receiveMessage(MessageConsumer consumer) throws JMSException {
        while (true) {
            try {
                // 建议异步处理收到的消息，确保receiveMessage函数里没有耗时逻辑。
                Message message = consumer.receive();
                processMessage(message);
            } catch (Exception e) {
                System.out.println("receiveMessage hand an exception: " + e.getMessage());
                e.printStackTrace();
            }
        }

    }

    private static MessageListener messageListener = message -> {
        try {
            // 建议异步处理收到的消息，确保onMessage函数里没有耗时逻辑。
            // 如果业务处理耗时过程过长阻塞住线程，可能会影响SDK收到消息后的正常回调。
            executorService.submit(() -> processMessage(message));
        } catch (Exception e) {
            System.out.println("submit task occurs exception: " + e.getMessage());
            e.printStackTrace();
        }
    };

    /**
     * 在这里处理您收到消息后的具体业务逻辑。
     */

    private static void  process(String content)
    {
        try {
            FileWriter file = new FileWriter("C:\\Users\\Administrator\\Desktop\\JsonDataToMysql\\src\\main\\resources\\data.json");
            file.write(content);
            file.close();
        }
        catch (Exception e){
            e.printStackTrace();
        }

    }
    private static void processMessage(Message message) {
        try {
            String body = message.getBody(String.class);
            String content = new String(body);
            System.out.println("receive an message, the content is " + content);
            process(content);
        } catch (Exception e) {
            System.out.println("processMessage occurs error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static JmsConnectionListener myJmsConnectionListener = new JmsConnectionListener() {
        /**
         * 连接成功建立。
         */
        @Override
        public void onConnectionEstablished(URI remoteURI) {
            System.out.println("onConnectionEstablished, remoteUri:" + remoteURI);
        }

        /**
         * 尝试过最大重试次数之后，最终连接失败。
         */
        @Override
        public void onConnectionFailure(Throwable error) {
            System.out.println("onConnectionFailure, " + error.getMessage());
        }

        /**
         * 连接中断。
         */
        @Override
        public void onConnectionInterrupted(URI remoteURI) {
            System.out.println("onConnectionInterrupted, remoteUri:" + remoteURI);
        }

        /**
         * 连接中断后又自动重连上。
         */
        @Override
        public void onConnectionRestored(URI remoteURI) {
            System.out.println("onConnectionRestored, remoteUri:" + remoteURI);
        }

        @Override
        public void onInboundMessage(JmsInboundMessageDispatch envelope) {
            System.out.println("onInboundMessage, " + envelope);
        }

        @Override
        public void onSessionClosed(Session session, Throwable cause) {
            System.out.println("onSessionClosed, session=" + session + ", cause =" + cause);
        }

        @Override
        public void onConsumerClosed(MessageConsumer consumer, Throwable cause) {
            System.out.println("MessageConsumer, consumer=" + consumer + ", cause =" + cause);
        }

        @Override
        public void onProducerClosed(MessageProducer producer, Throwable cause) {
            System.out.println("MessageProducer, producer=" + producer + ", cause =" + cause);
        }
    };
}
