const mqtt = require("mqtt");

const protocol = "mqtt";
const host = "broker.hivemq.com";
const port = "1883";
const path = "/mqtt";
const connectUrl = `${protocol}://${host}:${port}${path}`;
const topic = "sensor_data"; // Chủ đề MQTT để gửi dữ liệu
const ldr_topic = "ldr_demo";

// Tạo một đối tượng client MQTT
const client = mqtt.connect(connectUrl);

// Hàm để gửi dữ liệu MQTT
function publishSensorData() {
  // Tạo dữ liệu giả lập cho nhiệt độ, độ ẩm và ánh sáng
  const temperature = Math.random() * 30 + 20; // Giả lập nhiệt độ từ 20°C đến 50°C
  const humidity = Math.random() * 40 + 40; // Giả lập độ ẩm từ 40% đến 80%
  const light = Math.random() * 500 + 500; // Giả lập ánh sáng từ 500 lux đến 1000 lux

  const sensorData = {
    temperature: temperature.toFixed(2),
    humidity: humidity.toFixed(2),
    light: light.toFixed(2),
  };

  const message = JSON.stringify(sensorData);

  // Gửi dữ liệu lên chủ đề MQTT
  client.publish(topic, message, (err) => {
    if (err) {
      console.error("Lỗi khi publish tin nhắn:", err);
    } else {
      console.log("Đã gửi dữ liệu: ", sensorData);
    }
  });
}

// Khi kết nối thành công đến máy chủ MQTT
client.on("connect", () => {
  console.log("Kết nối thành công đến máy chủ MQTT");

  client.subscribe(topic, (err) => {
    if (err) {
      console.error("Lỗi khi subscribe vào chủ đề:", err);
    } else {
      console.log(`Đã subscribe vào chủ đề "${topic}"`);
    }
  });

  // Gửi dữ liệu định kỳ mỗi 5 giây
  setInterval(publishSensorData, 5000);
});

// Sự kiện khi nhận được tin nhắn
// client.on("message", (topic, message) => {
//   console.log(`Nhận tin nhắn từ chủ đề "${topic}": ${message}`);
// });

// Sự kiện khi bị ngắt kết nối
client.on("close", () => {
  console.log("Đã ngắt kết nối đến broker MQTT");
});
