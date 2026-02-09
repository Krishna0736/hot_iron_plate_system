# Hot Iron Plate Alert System

## Overview
The **Hot Iron Plate Alert System** is a safety-based hardware project designed to prevent accidental burns caused by contact with a heated electric iron. The system detects both the temperature of the iron plate and the proximity of a hand, and triggers an audible alert when the surface is dangerously hot.

This makes it especially useful in homes, hostels, and shared spaces where accidental contact with hot appliances is common.

---

## Objective
To design a low-cost, reliable, and real-time alert system that:
- Detects high temperature on an iron plate  
- Senses nearby hand presence  
- Warns users through a buzzer before contact  

---

## Components Used
- **Arduino Nano** – Main controller (compact and efficient)
- **10k ntc Thermistor** – For temperature measurement
- **IR Proximity Technology** – To detect hand presence
- **Piezo Buzzer** – For audio alert
- **Red LED** - Blinks when IR Pairs detect hand presence
- **Yellow LED** - Glow when temperature above 44 degree celsius
- **Connecting wires & power supply(Lithium Ion Battery 2S with Charging Module)**

---

## Working Principle
1. The **thermistor continuously measures the temperature** of the iron plate.  
2. The **IR Pairs detects if a hand is near the plate.**  
3. If:
   - Temperature is above the safe limit **AND**
   - A hand is detected nearby → The **buzzer turns ON** to warn the user.

---

## Features
- Low-cost and easy to build  
- Real-time alert system  
- Compact design using Arduino Nano  
- Energy efficient  
- Simple and reliable logic  

---

## Applications
- Household safety
- Hostels and PG accommodations  
- Laundry rooms  
- Child safety environments  

---

## Future Improvements
- To be used as a DIY kit, to easily install on excisting iron's
- Add an LCD display for temperature reading  
- Implement Bluetooth alerts via mobile app  
- Automatic power cut-off system  

---

## Developed By
Priyansh Verma & Krishna Gupta
