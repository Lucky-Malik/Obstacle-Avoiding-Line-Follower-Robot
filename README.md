# 🤖 Line Follower & Obstacle Avoiding Robot

> A flexible, intelligent robot that combines line-following precision with obstacle-avoidance logic using **Arduino UNO**, **L298N Motor Driver**, and **Ultrasonic + IR sensors**.

![Robot Image](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Line_follower_robot.jpg/640px-Line_follower_robot.jpg)  
<sub>*Representative image. Insert your own project image or GIF above for better impact.*</sub>

---

## 🚀 Introduction

In this fascinating project, we use an Arduino and an L298 Motor Driver to create a **Line Follower Robot** capable of **avoiding obstacles**. This robot is ideal for automating tasks like object transportation or even fun robotic racing. It dynamically adapts to its environment using both IR and Ultrasonic sensors.

---

## 🔧 Components Used

- Solderless Breadboard  
- 4-wheel Robot Car Kit  
- Arduino UNO  
- IR Sensors (x2)  
- L298 Motor Driver  
- Mini Servo Motor SG90  
- Ultrasonic Sensor HC-SR04 + Holder  
- 4Pcs Smart Robot Car Tyres & Wheels  
- Jumper Wires (Male–Male & Male–Female)  
- Hard Jumper Wires  
- On/Off Switch  
- 18650 Battery Holder (2 Cell)  
- 18650 Battery Cell 3.7V (x2)  

---

## 🔌 Circuit Diagram

The circuit is powered by two 3.7V batteries in series (7.4V total). IR sensors detect line paths, while an ultrasonic sensor mounted on a servo scans the front and sides for obstacles. Motor speed and direction are controlled via L298 Motor Driver and Arduino pins.

## 🧠 How It Works

- **Pin Definitions:** Motor (enA–B, in1–4), IR sensors (L_S, R_S), Ultrasonic (echo, trigger), Servo
- **Setup:** Initializes pins, sets PWM speeds, centers the servo, reads initial distances
- **Loop:** Reads sensors → determines path or obstacle → executes appropriate motor movement
- **Servo Scanning:** Servo sweeps sides to detect obstacles before deciding turn direction
- **Functions:** `forword()`, `backword()`, `turnLeft()`, `turnRight()`, `Stop()`

---

## 🧪 Hardware Testing

1. Power on robot
2. Calibrate IR sensors to detect black/white surfaces
3. Test forward, turning, and obstacle detection manually
4. Tune delays and speed as needed for optimal pathing

---

## ✅ Conclusion

This project demonstrates the power of combining **line-following logic** with **obstacle avoidance** using simple sensors and Arduino programming. It’s both a fun and educational introduction to **robotics**, **embedded systems**, and **autonomous navigation**.

---

## ✨ Future Improvements

- Add Bluetooth or WiFi remote control  
- Implement PID control for smoother movement  
- Train the robot to recognize colored paths using a camera module  

---

> Made with ❤️ by [Lokesh Malik](https://github.com/Lucky-Malik)