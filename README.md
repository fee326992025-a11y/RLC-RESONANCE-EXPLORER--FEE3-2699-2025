# Project Name: RLC RESONANCE EXPLORER

#### 

#### Project Description

This project is a console-based C++ application developed to numerically analyze the behavior of an RLC (Resistor–Inductor–Capacitor) circuit. The program allows the user to input electrical parameters and computes essential circuit characteristics based on established AC circuit theory.



The purpose of this implementation is to combine electrical engineering principles with computational programming techniques. By translating theoretical mathematical formulas into structured C++ code, the project demonstrates practical application of resonance analysis and frequency response evaluation.





##### Project Objectives

To implement the mathematical analysis of a series RLC circuit in C++.

2\. To compute the resonant frequency using standard circuit formulas.

3\. To calculate impedance magnitude at varying frequencies.

4\. To simulate frequency response through a sweep table.

5\. To apply numerical computation techniques within an engineering context.





**The series RLC circuit consists of:**

* Resistance (R)
* Inductance (L)
* Capacitance (C)

&nbsp;

The output of the circuit calculated by the program are:



##### 1\. Resonant Frequency



The resonant frequency (f₀) is calculated using:



f₀ = 1 / (2π√LC)

&nbsp;

##### 2\. Reactance



Inductive Reactance:

XL = 2πfL



Capacitive Reactance:

XC = 1 / (2πfC)



##### 3\. Impedance magnitude



The total impedance magnitude is given by:



Z = √(R² + (XL − XC)²)



&nbsp; 



#### Functional Description of the Program

The program performs the following major operations:



##### 1.User input module



The user is prompted to enter:

* Resistance (R) in ohms
* Inductance (L) in Henry
* Capacitance (C) in Farads



##### 2.Resonance Frequency Calculation



Using the provided L and C values, the program computes the resonant frequency and displays it clearly to the user.



##### 3\. Impedance Calculation Function



A dedicated computational section calculates impedance magnitude using:



-Resistance 

-Current frequency

-Inductance



##### 4\. Frequency Sweep Simulation



The program generates a frequency sweep table by:

* Calculating impedance at each frequency
* Displaying results in a table



##### 6\. Program Structure and Design



The project follows structured procedural programming principles.



###### **Libraries Used**

<iostream> – Input and output handling

<cmath> – Mathematical functions such as sqrt and pow

<iomanip> – Output formatting and alignment



##### Logical Flow

1\. Display program introduction.

2\. Accept user inputs.

3\. Calculate resonant frequency.

4\. Generate frequency sweep.

5\. Display results in a structured tabular form.

6\. End program execution.





The RLC Circuit Analysis Program successfully demonstrates the integration of electrical circuit theory with computational implementation in C++.

The system accurately computes resonance frequency and impedance values while simulating frequency response through a sweep table.











