# 🤖 Otto DIY Pet Mode — User Friendly Firmware

This is a simplified and **user-friendly firmware** for the [Otto DIY robot](https://www.ottodiy.com/).  
Instead of remembering complex movement IDs or command formats, you can now control Otto with **simple words** over Bluetooth — making it act more like a **pet**.  

---

## ✨ Features
- Control Otto with **plain text commands** via Bluetooth (9600 baud).
- Supports walking, turning, jumping, dancing, and singing.
- **Emotions** like `happy`, `sad`, and `sleep` combine **sound + movement**.
- **Dance mode**: Otto performs a fun mini-routine with sound.
- **Idle Pet Mode**: If left alone for 6s, Otto randomly sings or moves like a pet.
- Compact firmware suitable for **ATmega168/328**.

---

## 🛠 Hardware Setup

- **Board:** Arduino Uno / Nano (ATmega328/168)
- **Robot Kit:** Otto DIY or compatible 4-servo biped
- **Bluetooth Module:** HC-05 / HC-06
- **Wiring:**
  - Left Leg → D9  
  - Right Leg → D2  
  - Left Foot → D7  
  - Right Foot → D5  
  - Buzzer → D13  
  - BT RX → D12  
  - BT TX → D11  

---

## 🔧 Installation

1. Install the [Otto DIY Arduino Library](https://github.com/OttoDIY/OttoDIYLib).
2. Clone this repo or copy the `.ino` file into your Arduino IDE.
3. Select the correct **board** and **port** in Arduino IDE.
4. Upload the firmware to your Otto robot.

---

## 📱 Commands

Just send these **words** via Bluetooth (case-insensitive):

| Command   | Action                                    |
|-----------|-------------------------------------------|
| `forward` | Walk forward                              |
| `backward`| Walk backward                             |
| `left`    | Turn left                                 |
| `right`   | Turn right                                |
| `jump`    | Jump                                      |
| `dance`   | Small dance routine + sing                |
| `sing`    | Sing a cute sound                         |
| `happy`   | Happy sound + movement                    |
| `sad`     | Sad sound + gentle sway                   |
| `sleep`   | Go home + sleep sound                     |

---

## 💤 Idle Pet Mode
- If no command is received for **6 seconds**, Otto randomly:
  - Sings,
  - Swings,
  - Jitters,
  - Moves up and down.

This makes Otto feel **alive and pet-like**. 🐾

---

## 🚀 Example Usage
Using a **Bluetooth Terminal App** (Android/iOS):
- Connect to your Otto’s BT module.
- Type `dance` → Otto will swing, moonwalk, jitter, and sing happily.
- Type `happy` → Otto smiles with sounds and bounces.
- Leave it idle → Otto surprises you with random actions.







OttoDIY_PetMode_UserFriendly.ino
