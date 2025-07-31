#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

//colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"


using namespace std;

struct BiometricData {
    int heartRate;
    int blinksRate;
    int stressScale;
};

BiometricData generateData() {
    BiometricData data;
    data.heartRate = rand() % 71 + 60;
    data.blinksRate = rand() % 20 + 5;
    data.stressScale = rand() % 10 + 1;
    return data;
}

string analyzingDriveState(BiometricData data) {
    if (data.heartRate > 130 || data.stressScale == 10) {
        return "EMERGENCY";
    } else if (data.heartRate > 120 && data.stressScale >= 8) {
        return "STRESSED!";
    } else if (data.blinksRate < 8 && data.heartRate < 750) {
        return "DROWSY";
    } else {
        return "NORMAL";
    }

}

/** The following method displays the correct protocol
  * on what to do depending on which state of mind is displayed.
  * @param state : Current driver status
  */
void reactToState(const string& state) {
    if (state == "STRESSED!") {
        cout << "System Action: Playing calming music, lowering AC...\n";
    } else if (state == "DROWSY") {
        cout << "System Action: Flashing alert lights, sounding bepp.....\n";
    } else if (state == "EMERGENCY") {
        cout << "System Action: Activating emergency shutdown protocol...\n";
    } else {
        cout << "System Action: Maintaining normal driving environment.\n";
    }
}

/** This method repeatedly prompts the user
  * until they enter a valid integer.
  * @param prompt: What the user enters.
  */
int getValidInput(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // clear error state
            cin.ignore(10000, '\n'); // discard invalid input
            cout << RED << "Invalid input. Please enter a number only.\n" << RESET;

        } else {
            return value;
        }
    }
}

int main() {
    srand(time(0)); //seed for random
    ofstream logFile("driver_log.txt", ios::app); //this opens the log file in append mode

    cout << "============================\n";
    cout << " VIBE: Driver Status Console\n";
    cout << "============================\n\n";

    for (int i = 0; i < 5; i++) {
        BiometricData data = generateData(); //generates the random biometric data
        string state = analyzingDriveState(data); //gives right state depending on the random data

        cout << CYAN << "Heart Rate: " << data.heartRate << " BPM\n";
        cout << CYAN << "Blink Rate: " << data.blinksRate << " /min\n";
        cout << CYAN <<"Stress Level: " << data.stressScale << "/10\n";


        if (state == "STRESSED!" || state == "EMERGENCY") {
            cout << RED;
        }
        else if (state == "DROWSY") {
            cout << YELLOW;
        } else {
            cout << GREEN;
        }

        cout << "Status: " << state << RESET << endl;
        cout << "--------------------------------\n";
        reactToState(state); //Performs system action based on state
        //log to file
        logFile << "State: " << state
                << " | HR: " << data.heartRate
                << " | Blinks: " << data.blinksRate
                << " | Stress: " << data.stressScale << "\n";

        //optimal delay
        system("sleep 1");
    }

    logFile.close();
    cout << "Session logged in driver_log.txt\n";
    //prompts user to enter their own data
    cout << "\nWould you like to manually enter your own biometirc data? (yes/no) >";
    string userInput;
    cin >> userInput;

    if (userInput == "yes") {
        BiometricData manualData;

        manualData.heartRate = getValidInput("\nEnter Heart Rate (BPM): ");
        manualData.blinksRate = getValidInput("Enter Blink Rate (/min): ");
        manualData.stressScale = getValidInput("Enter Stress Level (1-10): ");


        string userState = analyzingDriveState(manualData);
        //display results
        cout << CYAN << "\n=====================\n";
        cout << " Your Manual Input Results\n";
        cout << "===========================\n" << RESET;

        cout << CYAN << "Heart Rate: " << manualData.heartRate << "BPM\n" <<RESET;
        cout << CYAN << "Blink Rate: " << manualData.blinksRate << "/min\n" << RESET;
        cout << CYAN << "Stress Level: " << manualData.stressScale << "/10\n" << RESET;

        if (userState == "STRESSED!" || userState == "EMERGENCY") {
            cout << RED;
        } else if (userState == "DROWSY"){
            cout << YELLOW;
        } else {
            cout << GREEN;
        }

        cout << "Status: " << userState << RESET << endl;
        reactToState(userState);

        // Log manual input to file
        logFile.open("driver_log.txt", ios::app);
        logFile << "User Input -> State: " << userState
                << " | HR: " << manualData.heartRate
                << " | Blinks: " << manualData.blinksRate
                << " | Stress: " << manualData.stressScale << "\n";
        logFile.close();
    }

    return 0;

}
