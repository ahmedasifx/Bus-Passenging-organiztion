// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<map>
#include<deque>
#include <iterator>

/*


this function is to read the passengeres from the file and identify which stop
*/


std:: vector<std::string> passenger() {

   char stop [] = {'A','B','C','D','E'};
    std::vector<std::string>name;
  
   

    


    std::ifstream file("people.txt");
    int noOfline=0;
    std::string str;
    std::string persone;
    std::string Mother;
    std::string child1;
    std::string child2;
    while (std::getline(file, str)) {
        //std::cout << "->" << str << std::endl;
        for (int j = 0; j < 5; j++) {
            if (j == noOfline) {
                for (int i = 0; i < str.size(); i++) {
                    // std::cout << "->" << str[i] << std::endl;
                    Mother = "mo";
                    child1 = "ch1";
                    child2 = "ch2";
                    persone = "";


                    if (str[i] != 'F') {


                        persone += str[i];
                        persone += stop[noOfline];
                        name.push_back(persone);
                    }
                    else
                    {
                        Mother += stop[noOfline];
                        name.push_back(Mother);
                        child1 += stop[noOfline];
                        name.push_back(child1);
                        child2 += stop[noOfline];
                        name.push_back(child2);


                    }


                }
            }
           

        }
        noOfline++;
     }


    

     return name;
     
  }
std::vector<std::string>  busSeats() 
{
    char colume[] = { 'A','B','C','D' };
    char Row[] = { '1','2','3','4','5','6','7','8' };
    

    std::vector<std::string>busseat;
    int NoOfCol = sizeof(colume) / sizeof(colume[0]);
    int NoOfrow = sizeof(Row) / sizeof(Row[0]);
    std::string Seats;
    for (int i = 0; i < NoOfCol; i++) {
        for (int j = 0; j < NoOfrow; j++) {
            Seats = "";
            Seats += colume[i];
            Seats += Row[j];
            busseat.push_back(Seats);

        }
    }


    return busseat;
}




 void bus(std::map<std::string, std::string> &Bus) {
    std::vector<std::string>seats = busSeats();
    std::string x = "empty";
    for (int i = 0; i < seats.size(); i++) {
        Bus.insert(std::pair<std::string, std::string>(seats[i], x));
    }
  
  
    
}
 /*


this function to identify which passengerges are entering
*/


void PassengersEntering(std::ofstream &fileA,char stop, std::vector<std::string>& x) {
    std::vector<std::string>Passenger = passenger();
    std::vector<std::string>Seats = busSeats();
    fileA << "passengengers entering"<<std::endl;
    std::cout << "passengengers entering" << std::endl;
    if (stop == 'A') {
        for (int i = 0; i < Passenger.size(); i++) {
            
          if (Passenger[i].back() == stop) {
              x.push_back(Passenger[i]);
                    
                    
             fileA << Passenger[i] << ",";
             




           }
            
        }
    }
    else if (stop == 'B') {
        for (int i = 0; i < Passenger.size(); i++) {
            if (Passenger[i].back() == stop) {
                fileA << Passenger[i] << ",";
                x.push_back(Passenger[i]);
                
            }
        }
    }
    else if (stop == 'C') {
        for (int i = 0; i < Passenger.size(); i++) {
            if (Passenger[i].back() == stop) {
                fileA << Passenger[i] << ",";
                x.push_back(Passenger[i]);
            }
        }
    }
    else if (stop == 'D') {
        for (int i = 0; i < Passenger.size(); i++) {
            if (Passenger[i].back() == stop) {
                fileA << Passenger[i] << ",";
                x.push_back(Passenger[i]);
            }
        }
    }
    else if (stop == 'E') {
        for (int i = 0; i < Passenger.size(); i++) {
            if (Passenger[i].back() == stop) {
                fileA << Passenger[i] << ",";
                x.push_back(Passenger[i]);
            }
        }
    }
    else if (stop == 'F') {
        fileA << "Last spot Know one enters" << ",";
        for (int i = 0; i < Seats.size(); i++) {
            x.push_back("empty");
        
        }
    }
    
    fileA << std::endl;
    
}

/*


this function to identify which passengerges are leaving
*/

void PassangersLeaving(std::ofstream &fileA, char stop) {
    std::vector<std::string>Passenger = passenger();
    std::vector<std::string>Seats = busSeats();
    fileA << "passengengers Leaving" << std::endl;
   
    char checkfront;
    std::string check;
    char checkmid;


    if (stop == 'A') {
        for (int i = 0; i < Passenger.size(); i++) {

            if (Passenger[i].back() == stop) {


                fileA << "_";
            }

        }
    }
    else if (stop == 'B') {
        int x = 0;
        for (int i = 0; i < Passenger.size(); i++) {
            
            check = Passenger[i];
            checkfront = check[0];
            checkmid = check[2];
            
            
            if (Passenger[i].back() == 'A'&&checkfront=='L' && x == 0) {
                fileA << Passenger[i] << ",";

                x++;

            }
        }
    }
    else if (stop == 'C') {
        int L = 0;
        int m= 0;
        int ch1 = 0;
        int ch2 = 0;
        for (int i = 0; i < Passenger.size(); i++) {
            
            check = Passenger[i];
            checkfront = check[0];
            checkmid = check[2];

            if (Passenger[i].back() == 'B' && checkfront == 'm'&&m==0) {
                fileA << Passenger[i] << ",";
                m++;

            }
            else if(Passenger[i].back() == 'B' && checkmid == '1' && ch1 == 0)
            {
                fileA << Passenger[i] << ",";
                ch1++;

            }
            else if(Passenger[i].back() == 'B' && checkmid == '2' && ch2 == 0)
            {
                fileA << Passenger[i] << ",";
                ch2++;

            }
            else if (Passenger[i].back() == 'A' && checkfront == 'L' && L == 0) {
                fileA << Passenger[i] << ",";
                L++;
            }

        }
    }
    else if (stop == 'D') {
        int x = 0;
        for (int i = 0; i < Passenger.size(); i++) {
            if (Passenger[i].back() == stop) {
                fileA <<"______";
            }
        }
    }
    else if (stop == 'E') {
        
        int m = 0;
        int ch1 = 0;
        int ch2 = 0;
        for (int i = 0; i < Passenger.size(); i++) {
            check = Passenger[i];
            checkfront = check[0];
            checkmid = check[2];
            if (Passenger[i].back() == 'B' && checkfront == 'm' && m == 0) {
                fileA << Passenger[i] << ",";
                m++;

            }
            else if (Passenger[i].back() == 'B' && checkmid == '1' && ch1 == 0)
            {
                fileA << Passenger[i] << ",";
                ch1++;

            }
            else if (Passenger[i].back() == 'B' && checkmid == '2' && ch2 == 0)
            {
                fileA << Passenger[i] << ",";
                ch2++;

            }

            
            
        }
    }
    else if (stop == 'F') {

    fileA << "Last stop everbody leaves";
      


     }



    fileA << std::endl;


}

/*


this function to identify which passengerges  seating potions
*/

void PassangersSeatingPosition(std::map<std::string, std::string>& Bus, char stop, std::ofstream& fileA, std::vector<std::string>& Passenger) {
    
    std::vector<std::string>Seats = busSeats();
    char checkfront;
    std::string check;
    char checkmid;
    std::string seats;
    char se;
    char fr;
    int Male = 0;
    int lady = 0;
    int mother = 0;
    int c1 = 0;
    int c2 = 0;
    for (int k = 0; k < Passenger.size(); k++) {
        check = Passenger[k];
        checkfront = check[0];
        checkmid = check[2];
        if (checkfront == 'L') {
            lady++;

        }
        else if (checkfront == 'M') {
            Male++;

        }
        else if (checkfront == 'm') {
            mother++;

        }
        else if (checkmid == '1') {
            c1++;

        }
        else if (checkmid == '2') {
            c2++;

        }

    }
   

    if (stop == 'A') {

        int cl = 0;
        int cm = 0;
        std::map<std::string, std::string>::iterator itr;
        for (int i = 0; i < Passenger.size(); i++) {
            
            for (int j = 0; j < Seats.size(); j++) {
                if (cl < lady) {
                    if (Passenger[i] == "LA")
                    {


                        

                        seats = Seats[j];

                        se = seats[1];
                        //std::cout << "the no" << se << std::endl;
                        fr = seats[0];
                        //std::cout << "the letter" << fr << std::endl;
                        if (fr == 'D' || fr == 'C') {
                            if (se == '1' || se == '2' || se == '3' || se == '4') {
                                itr = Bus.find(seats);
                                //std::cout << "the seat" << seats << std::endl;

                                if (itr != Bus.end()) {
                                    itr->second = Passenger[i];
                                    // std::cout << "the pas" << Passenger[i] << std::endl;
                                    cl++;
                                }
                            }
                        }

                    }
                }
                else if (Passenger[i] == "MA" && cm < Male) {
                    seats = Seats[j];
                    se = seats[1];
                    
                    fr = seats[0];
                    
                    if (fr == 'A' || fr == 'B' || fr == 'C' || fr == 'D') {
                        if (se == '5' || se == '6' || se == '7' || se == '8') {


                            itr = Bus.find(seats);
                            if (itr != Bus.end()) {
                                itr->second = Passenger[i];
                                cm++;

                            }
                        }
                    }
                }

            }
        }
    }
    else if (stop == 'B') {
        std::map<std::string, std::string>::iterator it;
        int v = 0;
        for (int j = 0; j < Seats.size(); j++) {
            it = Bus.find(Seats[j]);
            if (it != Bus.end()) {
                if (it->second == "LA" && v == 0) {
                    it->second = "empty";
                    v++;
                }

            }

        }
        int mo = 0;
        int ch1 = 0;
        int ch2 = 0;
        for (int i = 0; i < Passenger.size(); i++) {

            
            for (int j = 0; j < Seats.size(); j++) {
                if (mo < mother) {
                    if (Passenger[i] == "moB")
                    {


                        

                        seats = Seats[j];

                        se = seats[1];
                        
                        fr = seats[0];
                        
                        if (fr == 'D' || fr == 'C') {
                            if (se == '1' || se == '2' || se == '3' || se == '4') {
                                it = Bus.find(seats);
                                

                                if (it != Bus.end()) {
                                    if (it->second == "empty") {
                                        it->second = Passenger[i];
                                        
                                        mo++;
                                    }
                                }
                            }
                        }

                    }
                }
                else if (Passenger[i] == "ch1B" && ch1 < c1) {
                    seats = Seats[j];
                    se = seats[1];
                    
                    fr = seats[0];
                    
                    if (fr == 'A' || fr == 'B') {
                        if (se == '1' || se == '2' || se == '3' || se == '4') {


                            it = Bus.find(seats);
                            if (it != Bus.end()) {
                                if (it->second == "empty") {
                                    it->second = Passenger[i];
                                    ch1++;
                                }

                            }
                        }
                    }
                }
                else if (Passenger[i] == "ch2B" && ch2 < c2) {
                    seats = Seats[j];
                    se = seats[1];
                    
                    fr = seats[0];
                    
                    if (fr == 'A' || fr == 'B') {
                        if (se == '1' || se == '2' || se == '3' || se == '4') {


                            it = Bus.find(seats);
                            if (it != Bus.end()) {
                                if (it->second == "empty") {
                                    it->second = Passenger[i];
                                    ch2++;
                                }

                            }
                        }
                    }
                }

            }
        }
    }
    else if (stop == 'C') {
        int cl = 0;
        int cm = 0;
        std::map<std::string, std::string>::iterator itr;
        int v = 0;
        int mo = 0;
        int ch1 = 0;
        int ch2 = 0;
        for (int j = 0; j < Seats.size(); j++) {
            itr = Bus.find(Seats[j]);
            if (itr != Bus.end()) {
                if (itr->second == "LA" && v == 0) {
                    itr->second = "empty";
                    v++;
                }
                else if (itr->second == "moB" && mo == 0)
                {
                    itr->second = "empty";
                    mo++;
                }
                else if (itr->second == "ch1B" && ch1 == 0)
                {
                    itr->second = "empty";
                    ch1++;
                }
                else if (itr->second == "ch2B" && ch2 == 0)
                {
                    itr->second = "empty";
                    ch2++;
                }

            }

        }

        for (int i = 0; i < Passenger.size(); i++) {
          

            for (int j = 0; j < Seats.size(); j++) {





                if (cl < lady) {
                    if (Passenger[i] == "LC")
                    {


                       

                        seats = Seats[j];

                        se = seats[1];
                        
                        fr = seats[0];
                       
                        if (fr == 'D' || fr == 'C') {
                            if (se == '1' || se == '2' || se == '3' || se == '4') {
                                itr = Bus.find(seats);
                                

                                if (itr != Bus.end()) {
                                    if (itr->second == "empty") {
                                        itr->second = Passenger[i];
                                        
                                        cl++;
                                    }
                                }
                            }
                        }

                    }
                }
                else if (Passenger[i] == "MC" && cm < Male) {
                    seats = Seats[j];
                    se = seats[1];
                    
                    fr = seats[0];
                    
                    if (fr == 'A' || fr == 'B' || fr == 'C' || fr == 'D') {
                        if (se == '5' || se == '6' || se == '7' || se == '8') {


                            itr = Bus.find(seats);
                            if (itr != Bus.end()) {
                                if (itr->second == "empty") {
                                    itr->second = Passenger[i];
                                    cm++;
                                }
                            }
                        }
                    }
                }

            }
        }

    }
    else if (stop == 'D') {
        int cm = 0;
        std::map<std::string, std::string>::iterator itr;
        for (int i = 0; i < Passenger.size(); i++) {
          

            for (int j = 0; j < Seats.size(); j++) {
                if (Passenger[i] == "MD" && cm < Male) {
                    seats = Seats[j];
                    se = seats[1];
                    
                    fr = seats[0];
                    
                    if (fr == 'A' || fr == 'B' || fr == 'C' || fr == 'D') {
                        if (se == '5' || se == '6' || se == '7' || se == '8') {


                            itr = Bus.find(seats);
                            if (itr != Bus.end()) {
                                if (itr->second == "empty") {
                                    itr->second = Passenger[i];
                                    cm++;
                                }
                            }
                        }
                    }
                }



            }
        }



    }
    else if (stop == 'E') {
        int mo = 0;
        int ch1 = 0;
        int ch2 = 0;
        int cm = 0;
        std::map<std::string, std::string>::iterator itr;
        for (int j = 0; j < Seats.size(); j++) {
            itr = Bus.find(Seats[j]);
            if (itr != Bus.end()) {
                if (itr->second == "moB" && mo == 0)
                {
                    itr->second = "empty";
                    mo++;
                }
                else if (itr->second == "ch1B" && ch1 == 0)
                {
                    itr->second = "empty";
                    ch1++;
                }
                else if (itr->second == "ch2B" && ch2 == 0)
                {
                    itr->second = "empty";
                    ch2++;
                }

            }

        }
        for (int i = 0; i < Passenger.size(); i++) {
            //check = Passenger[i];
            //checkfront = check[0];
           // checkmid = check[2];
            //seats = Seats[i];

            //se = seats[0];

            for (int j = 0; j < Seats.size(); j++) {
                if (Passenger[i] == "ME" && cm < Male) {
                    seats = Seats[j];
                    se = seats[1];
                    // std::cout << "the no" << se << std::endl;
                    fr = seats[0];
                    //std::cout << "the letter" << fr << std::endl;
                    if (fr == 'A' || fr == 'B' || fr == 'C' || fr == 'D') {
                        if (se == '1' || se == '2' || se == '3' || se == '4' || se == '5' || se == '6' || se == '7' || se == '8') {


                            itr = Bus.find(seats);
                            if (itr != Bus.end()) {
                                if (itr->second == "empty") {
                                    itr->second = Passenger[i];
                                    cm++;
                                }
                            }
                        }
                    }
                }



            }

        }





    }
    else if(stop == 'F')
    {
        std::map<std::string, std::string>::iterator itr;
        for (int i = 0; i < Passenger.size(); i++) {


            for (int j = 0; j < Seats.size(); j++) {
                itr = Bus.find(Seats[j]);
                if (itr != Bus.end()) {
                    itr->second = Passenger[i];
                
                
                }
            
            }
        }

    }



}
void display(std::map<std::string, std::string>& Bus, std::ofstream& fileA,char a) {
    fileA << "************ the stop" << a << "*****************" << std::endl;
    std::map<std::string, std::string>::iterator it;
    for (it = Bus.begin(); it != Bus.end(); ++it) {


        fileA << "the seat:" << it->first << "the passenger" << it->second << std::endl;



    }

    fileA << std::endl;

}

void run() {
    std::map<std::string, std::string>::iterator itr;
    std::map<std::string, std::string> b;
    bus(b);

    std::ofstream myfileA;
    std::ofstream myfileB;
    std::ofstream myfileC;
    std::ofstream myfileD;
    std::ofstream myfileE;
    std::ofstream myfileF;
    myfileA.open("stopA.txt");
    myfileB.open("stopB.txt");
    myfileC.open("stopC.txt");
    myfileD.open("stopD.txt");
    myfileE.open("stopE.txt");
    myfileF.open("stopF.txt");


    std::vector<std::string>Passenger;
    std::vector<std::string>PassengerB;
    std::vector<std::string>PassengerC;
    std::vector<std::string>PassengerD;
    std::vector<std::string>PassengerE;
    std::vector<std::string>PassengerF;
    int x = 0;
   
   

    while (x < 5) {
        std::cout << "enter D to show each plan" << std::endl;
        char key;
        std::cin >> key;
        if (key=='D' && x == 0) {
            PassengersEntering(myfileA, 'A', Passenger);
            PassangersLeaving(myfileA, 'A');
            PassangersSeatingPosition(b, 'A', myfileA, Passenger);
            display(b, myfileA, 'A');
            x++;
        }
        else if(key == 'D' && x==1)
        {

            PassengersEntering(myfileB, 'B', PassengerB);
            PassangersLeaving(myfileB, 'B');
            PassangersSeatingPosition(b, 'B', myfileB, PassengerB);
            display(b, myfileB, 'B');
            x++;

        }
        else if (key == 'D' && x == 2) {
            PassengersEntering(myfileC, 'C', PassengerC);
            PassangersLeaving(myfileC, 'C');
            PassangersSeatingPosition(b, 'C', myfileC, PassengerC);
            display(b, myfileC, 'C');
            x++;
        }
        else if (key == 'D' && x == 3) {
            PassengersEntering(myfileD, 'D', PassengerD);
            PassangersLeaving(myfileD, 'D');
            PassangersSeatingPosition(b, 'D', myfileD, PassengerD);
            display(b, myfileD, 'D');
            x++;
        }
        else if(key == 'D' && x==4)
        {
            PassengersEntering(myfileE, 'E', PassengerE);
            PassangersLeaving(myfileE, 'E');
            PassangersSeatingPosition(b, 'E', myfileE, PassengerE);
            display(b, myfileE, 'E');

            PassengersEntering(myfileF, 'F', PassengerF);
            PassangersLeaving(myfileF, 'F');
            PassangersSeatingPosition(b, 'F', myfileF, PassengerF);
            display(b, myfileF, 'F');
            x++;
        }
    }
}


    



int main()
{

    run();

     






    }


