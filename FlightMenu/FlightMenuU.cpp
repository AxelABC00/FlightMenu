#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Passenger {
private:
	
    string name;
    string surname;
    char gender;

public:
    
    Passenger(string& Name, string& Surname, char Gender) : name(Name), surname(Surname), gender(Gender) {
    }

    string getName() {
        return name;
    }

    void setName(string& Name) {
        name = Name;
    }

    string getSurname() {
        return surname;
    }

    void setSurname(string& Surname) {
        surname = Surname;
    }

    char getGender() {
        return gender;
    }
};

class Flight {
private:
	
    string flightNo;
    int maximumNumberOfseats;
    int numberOfpassengers;
    vector<Passenger> listOfpassengers;

public:
    Flight(string& fNo, int max) : flightNo(fNo), maximumNumberOfseats(max), numberOfpassengers(0) {}

    string getFlightNo() {
        return flightNo;
    }

    int  getMaximumNumberOfseats() {
        return maximumNumberOfseats;
    }
    int numberOfPassengers()  {
        return numberOfpassengers;
    }

    bool reserveSeat(Passenger& passenger) {
        if (numberOfpassengers < maximumNumberOfseats) {
            listOfpassengers.push_back(passenger);
            numberOfpassengers++;
            return true;
        }
        return false;
    }

    bool cancelReservation( string& passengerName,  string& passengerSurname) {
        for (auto x = listOfpassengers.begin(); x != listOfpassengers.end(); ++x) {
            if (x->getName() == passengerName && x->getSurname() == passengerSurname) {
                x = listOfpassengers.erase(x);
                numberOfpassengers--;
                return true;
            }
        }
        return false;
    }
    
void displayPassengers() {
    
    int size = listOfpassengers.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (listOfpassengers[j].getSurname()[0] > listOfpassengers[j + 1].getSurname()[0]) {
                
                Passenger temp = listOfpassengers[j];
                listOfpassengers[j] = listOfpassengers[j + 1];
                listOfpassengers[j + 1] = temp;
            }
        }
    }

    cout << left << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Gender" << endl;
    for (auto& passenger : listOfpassengers) {
        cout << left<< setw(20)<< passenger.getSurname() << setw(20) << passenger.getName() << setw(10) << passenger.getGender() << endl;
    }
}


    
    vector<Passenger> getPassengerList() {
        return listOfpassengers;
    }
    
};

bool check(string name,string surname) {
	char c;
	for(char c:name){
		if(isalpha(c)) {
			
		}else {
			cout << "Invalid input in Name. Please enter only alphabetic characters." << endl;
			return false;
		}
	}
	for(char c: surname) {
		if(isalpha(c)) {
			
		}else {
			cout << "Invalid input in Surname. Please enter only alphabetic characters." << endl;
			return false;
		}
	}
	return true;
}
int main() {
    string n = "ABC";
    Flight flight(n, 25);

    int run = 1;
    int choice;
    while (run) {
        cout << setw(20) << "***Flight Menu***\n" << endl;
        cout << left << setw(2) << "1. Reserve a Ticket" << endl;
        cout << left << setw(2) << "2. Cancel a Reservation" << endl;
        cout << left << setw(2) << "3. Check Reservation" << endl;
        cout << left << setw(2) << "4. Display Passengers" << endl;
        cout << left << setw(2) << "5. Exit\n" << endl;
        cout << "Please enter (1-2-3-4-5): ";

        cin >> choice;
        if (choice == 1) {
            string name, surname;
            char gender;
            
            cout << "Enter passenger details (Name and Surname):" << endl;
            cin.ignore();
            
            cout << "Name: ";
            getline(cin, name);
            
            cout << "Surname: ";
            getline(cin, surname);
            
            if(check(name,surname) == false) {
            	main();
			}
			
            cout << "Gender (M/F): ";
            cin >> gender;
            
            if (gender != 'M' && gender != 'F' && gender !='m' && gender !='f') {
            	
                cout << "Invalid gender input. Please enter 'M' or 'F'." << endl;
                
            } else {
            	
                Passenger passenger(name, surname, gender);
                
                if (flight.reserveSeat(passenger)) {
                	
                    cout << "Ticket reserved successfully." << endl;
                } else {
                	
                    cout << "The flight is already full." << endl;
                }
            }
        } else if (choice == 2) {
        	if(flight.numberOfPassengers() ==0) {
        		cout<<"no passengers are registered"<<endl;
			} else {
			
            string cancelName, cancelSurname;
            cout << "Enter passenger details to cancel the reservation (Name and Surname):" << endl;
            cin.ignore();
            
            cout << "Name: ";
            getline(cin, cancelName);
            
            cout << "Surname: ";
            getline(cin, cancelSurname);
            
            if (flight.cancelReservation(cancelName, cancelSurname)) {
            	
                cout << "Reservation cancelled successfully." << endl;
            } else {
            	
                cout << "Passenger not found." << endl;
            }
        }
        }else if (choice == 3) {
        	if(flight.numberOfPassengers() ==0) {
        		cout<<"no passengers are registered"<<endl;
			}else  {
			
            string checkName, checkSurname;
            cout << "Enter passenger details to check the reservation Name and Surname: " << endl;
            cin.ignore();
            cout <<"Name: ";
            getline(cin, checkName);
            cout <<"Surname: ";
            getline(cin, checkSurname);
            
            int control = 0;
            for (auto& passenger : flight.getPassengerList()) {
                if (passenger.getName() == checkName && passenger.getSurname() == checkSurname) {
                    cout << "Reservation found.\n" << endl;
                    control = 1;
                    break;
                }
                else {
                	if(control ==0)
                cout << "Reservation not found.\n" << endl;
				}
            }
            
        }
                
            
        } else if (choice == 4) {
        	if(flight.numberOfPassengers() ==0) {
        		cout<<"no passengers are registered"<<endl;
			}else {
			
            cout << "Passenger List:" << endl;
            flight.displayPassengers();
        }
        } else if (choice == 5) {
            run = 0;
            
        }else {
            cout << "Your choice is wrong please enter (1-2-3-4-5)\n" << endl;
        }
    }
    return 0;
}


