const mqtt = require("mqtt");

const protocol = "mqtt";
const host = "broker.hivemq.com";
const port = "1883";
const path = "/mqtt";
const connectUrl = `${protocol}://${host}:${port}${path}`;
const led_topic = "led_demo";
const fan_topic = "fan_demo";
const sensor_topic = "sensor_demo";

// Tạo một đối tượng client MQTT
const client = mqtt.connect(connectUrl);

// Hàm để gửi dữ liệu MQTT
function publishData(topic, message) {
  // Gửi dữ liệu lên chủ đề MQTT
  client.publish(topic, message, (err) => {
    if (err) {
      console.error("Lỗi khi publish tin nhắn:", err);
    } else {
      console.log("Đã gửi dữ liệu");
    }
  });
}

function subscribeTopic(topic) {
  client.subscribe(topic, (err) => {
    if (err) {
      console.error("Lỗi khi subscribe vào chủ đề:", err);
    } else {
      console.log(`Đã subscribe vào chủ đề "${topic}"`);
    }
  });
}

// Khi kết nối thành công đến máy chủ MQTT
client.on("connect", () => {
  console.log("Kết nối thành công đến máy chủ MQTT");

  subscribeTopic(sensor_topic);
  subscribeTopic(led_topic);
  subscribeTopic(fan_topic);
});

// Sự kiện khi nhận được tin nhắn
client.on("message", (topic, message) => {
  if (topic === sensor_topic) {
    console.log("Received message on topic", topic);
    try {
      const data = JSON.parse(message);
      console.log("Message:", data);
    } catch (e) {
      console.error("Error parsing JSON:", e);
    }
  }
});

// Sự kiện khi bị ngắt kết nối
client.on("close", () => {
  console.log("Đã ngắt kết nối đến broker MQTT");
});
