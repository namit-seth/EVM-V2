
# 🗳️ Building a Simple Electronic Voting Machine (EVM) with Arduino

**Author**: Namit Seth  
**Project Repository**: [EVM-V2 on GitHub](https://github.com/namit-seth/EVM-V2)  
**TinkerCAD Simulation**: [Live Circuit Simulation](https://www.tinkercad.com/things/6YQpShvm2TO-evm-v2)

---

## 🔧 Introduction

Electronic Voting Machines (EVMs) are a modern replacement for traditional ballot paper-based voting systems. They offer faster results, reduced human error, and are environmentally friendly. In this blog, I’ll walk you through my **Arduino-based EVM Project (V2)**—a simplified version that demonstrates the working of a voting machine with live vote tallying and result display on an LCD screen.

---

## 🧠 Project Objective

To simulate an EVM that:
- Allows three candidates to receive votes via push buttons.
- Displays a real-time voting interface.
- Shows the winner after voting ends.
- Uses simple components that can be breadboarded and simulated using TinkerCAD.

---

## 🔩 Components Used

- 1 x Arduino Uno  
- 1 x 16x2 LCD display  
- 3 x Push buttons (for voting)  
- 1 x Push button (to end voting & show result)  
- 3 x LEDs (to indicate votes being cast)  
- 1 x Buzzer (to confirm button press)  
- Resistors: 220Ω, 1kΩ  
- Breadboard and jumper wires

---

## 🔌 Circuit Diagram

![Circuit Diagram](https://github.com/namit-seth/EVM-V2/blob/main/EVM%20V2.png?raw=true)

🔗 [View on TinkerCAD](https://www.tinkercad.com/things/6YQpShvm2TO-evm-v2)

---

## 💻 How It Works

1. **Initialization**: The LCD displays a welcome message. All vote counters are set to zero.
2. **Voting Process**:  
   - Each push button corresponds to a candidate.  
   - On pressing a button:  
     - The respective vote counter increases.  
     - The LED blinks and the buzzer sounds as feedback.  
3. **Ending Voting**:  
   - Press the “Result” button to stop voting.  
   - The LCD displays the vote count for each candidate and highlights the winner.  
   - In case of a tie, the LCD indicates it.

---

## 🧠 Code Overview

The project logic is written in Arduino’s C-style syntax. You can find the full `.ino` file [here](https://github.com/namit-seth/EVM-V2/blob/main/EVM_V2.ino).

Some key logic includes:

```cpp
if (digitalRead(button1) == HIGH) {
  votesA++;
  tone(buzzer, 1000, 200);
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
}
```

The LCD library (`LiquidCrystal.h`) is used to handle display outputs:

```cpp
lcd.setCursor(0, 0);
lcd.print("Votes A: ");
lcd.print(votesA);
```

---

## 🔍 What I Learned

- Basics of user interface feedback using LCD and buzzer  
- Debouncing and logical state detection with buttons  
- Real-world application of conditional logic  
- Hands-on practice with TinkerCAD and Arduino IDE  

---

## 📈 Future Improvements

- Add password-protected access to the result button  
- Implement EEPROM to store votes after power loss  
- Replace buttons with capacitive touch sensors  
- Add SD card logging for audit trail

---

## 🧑‍💻 Try It Yourself!

🔗 GitHub: [namit-seth/EVM-V2](https://github.com/namit-seth/EVM-V2)  
🔗 TinkerCAD: [EVM V2 Simulation](https://www.tinkercad.com/things/6YQpShvm2TO-evm-v2)

Feel free to fork the project and add your own creative twist!
