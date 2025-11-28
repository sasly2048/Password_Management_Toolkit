# 🔑 Password Management Toolkit 

A Password Management Toolkit is a versatile C program designed to enhance user security by providing two core functionalities : a **Password Strength Checker** and a **Random Password Generator**.

- **Password Strength Checker (PSC) :** This module evaluates the robustness of a user-entered password. 
- **Random Password Generator (RPG) :** This new feature creates strong, random passwords based on user-specified criteria.      

----

## 🧠 Features  :

 * **Dual Functionality** - The program serves two main purposes: checking the strength of an existing password and generating a new, random one.
 * **Real-time Password Evaluation** – Analyses the password as it is entered.
 * **Comprehensive Analysis** - It evaluates passwords based on essential criterionas.    
 * **Strength Classification** – Categorizes passwords as Weak, Moderate, or Strong.
 * **User-Friendly Output** – Displays clear feedback to guide users toward stronger passwords.
 * **Efficient Logic** – Built using simple C constructs for clarity and performance.
   
---

## 🧩 Password Strength Criteria  

| Criteria | Description | Points |
|-----------|--------------|--------|
| Length ≥ 8 characters | Ensures basic security length | +1 |
| Contains uppercase letters (A–Z) | Improves complexity | +1 |
| Contains lowercase letters (a–z) | Improves diversity | +1 |
| Contains digits (0–9) | Adds numerical strength | +1 |
| Contains special characters (!, @, #, etc.) | Adds unpredictability | +1 |

**Score Classification**  

| Score | Classification |
|--------|----------------|
| 1 | 🔴 Very Weak |
| 2 | 🟠 Weak |
| 3 | 🟡 Moderate |
| 4 | 🟢 Strong |
| 5 | 🟣 Very Strong |

---

## 🌐 Test Online 

https://github.com/codespaces/psychic-space-parakeet-4j664xp54gv9cjxq5?editor=web 

- In Terminal, paste the following command : _gcc code.c -o code && ./code_

---
