//Function to construct RLC Resonance Explorer in Series
//To calculate Resonance frequency, Q-factor, Sweep frequency values
//And generate output table for magnitude
//Using inputs from the user

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


//Function to calculate Resonance frequency
//Take inductance and capacitance as parameters
//Returns Resonance frequency as a double
double calculateResonanceFrequency (double inductance, double capacitance)
{
    const double PI=3.142;
    return 1/(2*PI*sqrt(inductance*capacitance));
}

//Function to calculate Q-factor
//Take resistance, inductance and capacitance as parameters
//Returns  Q-factor as a double
double calculateQFactor (double resistance, double inductance, double capacitance)
{
    return (1/resistance)*sqrt(inductance/capacitance);
}

//Function to calculate Resonance angular frequency
//Take inductance and capacitance as parameters
//Returns Resonance angular frequency as a double
double calculateResonanceAngularFrequency (double inductance, double capacitance)
{
  return 1/sqrt(inductance*capacitance);
}

//Function to calculate Impedance magnitude
//Take inductance, capacitance, resonance angular frequency and resistance as parameters
//Return Impedance magnitude as a double
double calculateImpedanceMagnitude (double resistance, double capacitance, double inductance, double resonanceangularfrequency)
{
    return sqrt(
       pow(resistance,2)+
        pow((resonanceangularfrequency*inductance)-
        (1/(resonanceangularfrequency*capacitance)),2)
        );
}

//Function to calculate current magnitude
//Take Impedance magnitude and input voltage as parameters
//Return current magnitude as a double
double calculateCurrentMagnitude (double inputvoltage, double impedancemagnitude)
{
    return inputvoltage/impedancemagnitude;
}

// Function to get valid positive input from the user
// Ensures the user enters a number greater than zero
double getPositiveInput(const std::string& promptMessage)
{
    double value;

    while (true)
    {
        std::cout << promptMessage;
        std::cin >> value;

        // Check if input is valid and positive
        if (std::cin.fail() || value <= 0)
        {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n'); // Discard invalid input
            std::cout << "Error: Please enter a positive number.\n\n";
        }
        else
        {
            break; // Valid input received
        }
    }

    return value;
}

// Main function - Entry point of the program
int main()
{
    std::cout << "=========================================\n";
    std::cout << " Resonance frequency                     \n";
    std::cout << " Q-factor                                \n";
    std::cout << " Resonance angular frequency             \n";
    std::cout << " Impedance magnitude                     \n";
    std::cout << " Current magnitude                       \n";
    std::cout << "=========================================\n";

//Get dimensions from the user
double inductance, resistance, capacitance, inputvoltage
{};
   std::cout << "Enter the resistance (ohms):";
   std::cin >> resistance;
   std::cout << "Enter the capacitance (farad):";
   std::cin >> capacitance;
   std::cout << "Enter the inductance (henry):";
   std::cin >> inductance;
   std::cout << "Enter the input voltage (volts):";
   std::cin >> inputvoltage;


//Calculate Resonance frequency,Q-factor, Resonance angular frequency, Impedance magnitude, Current magnitude
double resonancefrequency=calculateResonanceFrequency (inductance, capacitance);
double QFactor=calculateQFactor (resistance, inductance, capacitance);
double resonanceangularfrequency=calculateResonanceAngularFrequency (inductance, capacitance);
double impedancemagnitude=calculateImpedanceMagnitude (resistance, capacitance, inductance, resonanceangularfrequency);
double currentmagnitude=calculateCurrentMagnitude (inputvoltage, impedancemagnitude);

    //Display results to the user
    std::cout << "\n====================================\n";
    std::cout << "            RESULTS                 \n";
    std::cout << "====================================\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Resonance frequency:"<<resonancefrequency<<"Hz\n";
    std::cout << "QFactor:"<<QFactor<<"\n";
    std::cout << "Resonance angular frequency:"<<resonanceangularfrequency<<"Hz\n";
    std::cout << "Impedance Magnitude:"<<impedancemagnitude<<"ohms\n";
    std::cout << "Current Magnitude:"<<currentmagnitude<<"A\n";
    std::cout << "====================================\n";

//Frequency sweep parameters
double f_start, f_end, f_step;
   std::cout << "\n Enter start frequency (Hz):";
   std::cin >> f_start;
   std::cout << "Enter end frequency (Hz):";
   std::cin >> f_end;
   std::cout << "Enter step frequency (Hz):";
   std::cin >> f_step;

        //Output table
   std::cout << "\n Frequency Response Table\n";
   std::cout << "=================================\n";
   std::cout << "Frequency(Hz)\tImpedanceMagnitude(ohms)\tCurrentMagnitude(A)\n";
   std::cout << "=================================\n";

for (double f=f_start; f<=f_end; f+=f_step)
{

    double resonanceangularfrequency=
                                    calculateResonanceAngularFrequency(inductance,
                                                                       capacitance);
    double impedancemagnitude =
            calculateImpedanceMagnitude(resistance,
                                        capacitance,
                                        inductance,
                                        resonanceangularfrequency);

    double currentmagnitude  =
            calculateCurrentMagnitude(inputvoltage, impedancemagnitude);

    std::cout << f << "\t\t" <<impedancemagnitude << "\t\t" <<currentmagnitude << "\n";

}


   return 0;
}
