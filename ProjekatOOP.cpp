
//  ███████ ████████  ██████  ██████  ███████                                                       
//  ██         ██    ██    ██ ██   ██ ██                                                            
//  ███████    ██    ██    ██ ██████  █████                                                         
//       ██    ██    ██    ██ ██   ██ ██                                                            
//  ███████    ██     ██████  ██   ██ ███████                                                       
//                                                                                                  
//                                                                                                  
//  ███    ███  █████  ███    ██  █████   ██████  ███████ ███    ███ ███████ ███    ██ ████████     
//  ████  ████ ██   ██ ████   ██ ██   ██ ██       ██      ████  ████ ██      ████   ██    ██        
//  ██ ████ ██ ███████ ██ ██  ██ ███████ ██   ███ █████   ██ ████ ██ █████   ██ ██  ██    ██        
//  ██  ██  ██ ██   ██ ██  ██ ██ ██   ██ ██    ██ ██      ██  ██  ██ ██      ██  ██ ██    ██        
//  ██      ██ ██   ██ ██   ████ ██   ██  ██████  ███████ ██      ██ ███████ ██   ████    ██        
//                                                                                                  
//                                                                                                  
//  ███████  ██████  ███████ ████████ ██     ██  █████  ██████  ███████                             
//  ██      ██    ██ ██         ██    ██     ██ ██   ██ ██   ██ ██                                  
//  ███████ ██    ██ █████      ██    ██  █  ██ ███████ ██████  █████                               
//       ██ ██    ██ ██         ██    ██ ███ ██ ██   ██ ██   ██ ██                                  
//  ███████  ██████  ██         ██     ███ ███  ██   ██ ██   ██ ███████                             
//                                                                                                  
//                                                                                                  


#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


//  ██    ██ ████████ ██ ██          ███████ ██    ██ ███    ██ ██   ██  ██████ ██      ██ ███████ 
//  ██    ██    ██    ██ ██          ██      ██    ██ ████   ██ ██  ██  ██      ██      ██ ██      
//  ██    ██    ██    ██ ██          █████   ██    ██ ██ ██  ██ █████   ██      ██      ██ █████   
//  ██    ██    ██    ██ ██          ██      ██    ██ ██  ██ ██ ██  ██  ██      ██ ██   ██ ██      
//   ██████     ██    ██ ███████     ██       ██████  ██   ████ ██   ██  ██████ ██  █████  ███████ 
//                                                                                                 
//                                                                                                 

/*
    Funkcija koja vraca duzinu stringa
*/
int custom_strlen(char* pocetak, int current){
    if(*pocetak != '\0')
        return custom_strlen(pocetak+1,current+1);
    return current;
}

/*
    Ucitava sve unesene karaktere do '\n' tj endl tj karaktera za oznaku kraja linije
*/
string read_line(){
    string line;
    getline(cin,line);
    
    return line;
}

double read_double(){
    double value;
    cin >> value;
    cin.ignore(1,'\n');

    return value;
}   

int read_int(){
    int value;
    cin >> value;
    cin.ignore(1,'\n');

    return value;
}
/*
    Spaja dva char* (char[]) tipa u jedan gdje se drugi nastavlja na prvi
*/
char* string_merge(const char* String1, const char* String2)
{
    char* full_text = (char *) malloc((strlen(String1) + strlen(String2)) * sizeof(char));
    strcpy(full_text, String1);
    strcat(full_text, String2);

    return full_text;
}

/*
    Pretvara string datetype u char[] (char*) datetype sa istim vrijednostima
*/
char* string_to_char(string line){
    char* char_array = (char*)(malloc(sizeof(char)*(line.length())));
    strcpy(char_array, line.c_str());
    return char_array;
}

/*
    Pretvara char* u int datetype, tj iz niza karaktera uzma numericke vrijednosti i 
    pretvara ih u korektan Integer tip.
*/
int string_to_int(char* stringNumber){
    int result = 0;
    bool negative = false;

    for(int i=0;i<strlen(stringNumber);i++){
        if(stringNumber[i] == '-'){
            negative = true;
            continue;
        }

        result = result * 10 + (stringNumber[i]-48);
    }
    
    return !negative? result : -result;
}
/*
    Pretvara char* u double datetype, tj iz niza karaktera uzma numericke vrijednosti i 
    pretvara ih u korektan Double tip.
*/
double string_to_double(char* stringNumber){
    double result = 0;
    bool negative = false;

    for(int i=0, counter = 0;i<strlen(stringNumber);i++){
        if(stringNumber[i] == '-'){
            negative = true;
            continue;
        }

        if(stringNumber[i] == '.'){
            counter = 1;
            continue;
        }

        if(!counter){
            result = (long double)(result * 10 + (stringNumber[i]-48));
            continue;
        }

        result = result + (long double)((stringNumber[i]-48)/pow(10,counter++));
    }
    
    return !negative ? result : -result;
}

/*
    Uzima segment char* (char[]) oznacenog sa indexom offseta u 
    prosljedjenom stringu i kolicinom karaktera koju 
    zelimo uzeti iz tog stringa
*/
char* char_substring(char* charString, int offset, int size){
    char* full_text = (char *) malloc(size * sizeof(char));
    for(int i=0;i<size;i++)
        full_text[i] = charString[offset+i];
    
    full_text[size] = '\0';
    return full_text;
}




//  ██████   █████  ████████ ███████ ████████ ██ ███    ███ ███████ 
//  ██   ██ ██   ██    ██    ██         ██    ██ ████  ████ ██      
//  ██   ██ ███████    ██    █████      ██    ██ ██ ████ ██ █████   
//  ██   ██ ██   ██    ██    ██         ██    ██ ██  ██  ██ ██      
//  ██████  ██   ██    ██    ███████    ██    ██ ██      ██ ███████ 
//                                                                  
//                                                                  

typedef struct Datetime
{
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Second;

    // 01-01-1990 11:11:11
    char* format_in_string()
    {
        char *stringDay = string_merge(Day < 10 ? "0" : "", to_string(Day).c_str());
        char *stringMonth = string_merge(Month < 10 ? "0" : "", to_string(Month).c_str());
        const char *stringYear = string_merge(to_string(Year).c_str(),"");

        const char *stringHour = string_merge(Hour < 10 ? "0" : "", to_string(Hour).c_str());
        const char *stringMinute = string_merge(Minute < 10 ? "0" : "", to_string(Minute).c_str());
        const char *stringSecond = string_merge(Second < 10 ? "0" : "", to_string(Second).c_str());

        return string_merge(
            string_merge(
                string_merge(
                    string_merge(
                        string_merge(
                            string_merge(
                                string_merge(
                                    string_merge(
                                        string_merge(
                                            string_merge(stringDay, "-"),
                                            stringMonth),
                                        "-"),
                                    stringYear),
                                " "),
                            stringHour),
                        ":"),
                    stringMinute),
                ":"),
            stringSecond);
    }

    void format_from_string(char* stringDatetime){
        Day = string_to_int(char_substring(stringDatetime,0,2));
        Month = string_to_int(char_substring(stringDatetime,3,2));
        Year = string_to_int(char_substring(stringDatetime,6,4));
        Hour = string_to_int(char_substring(stringDatetime,11,2));
        Minute = string_to_int(char_substring(stringDatetime,14,2));
        Second = string_to_int(char_substring(stringDatetime,17,2));
    }

    int compare(Datetime datetime){
        if(Year < datetime.Year) return -1;
        if(Year > datetime.Year) return 1;

        if(Month < datetime.Month) return -1;
        if(Month > datetime.Month) return 1;
        
        if(Day < datetime.Day) return -1;
        if(Day > datetime.Day) return 1;
        
        if(Hour < datetime.Hour) return -1;
        if(Hour > datetime.Hour) return 1;

        if(Minute < datetime.Minute) return -1;
        if(Minute < datetime.Minute) return 1;

        if(Second < datetime.Second) return -1;
        if(Second > datetime.Second) return 1;

        return 0;
    }

    void copy(Datetime datetime){
        Day = datetime.Day;
        Month = datetime.Month;
        Year = datetime.Year;
        Hour = datetime.Hour;
        Minute = datetime.Minute;
        Second = datetime.Second;
    }
} Datetime;
Datetime construct_datetime(int day, int month, int year, int hour, int minute, int second){
    Datetime datetime;
    datetime.Day = day;
    datetime.Month = month;
    datetime.Year = year;
    datetime.Hour = hour;
    datetime.Minute = minute;
    datetime.Second = second;

    return datetime;
}
Datetime construct_from_string(char* string_datetime){
    Datetime datetime;
    datetime.format_from_string(string_datetime);
    return datetime;
}
// Preuzeto sa: https://stackoverflow.com/questions/16357999/current-date-and-time-as-string/16358264
Datetime get_current_datetime(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    string str(buffer);

    return construct_from_string(string_to_char(str));
}




//  ██████   █████  ██████  ███    ██ ██ ██   ██ 
//  ██   ██ ██   ██ ██   ██ ████   ██ ██ ██  ██  
//  ██████  ███████ ██   ██ ██ ██  ██ ██ █████   
//  ██   ██ ██   ██ ██   ██ ██  ██ ██ ██ ██  ██  
//  ██   ██ ██   ██ ██████  ██   ████ ██ ██   ██ 
//                                               
//                                               

typedef struct Radnik{
    int Id; 
    char* FirstName;
    char* LastName;
    char* JMBG;
    Datetime Birthday;
    char* PhoneNumber;

    void print(){
        cout << "[" << Id << "] " << LastName << " " << FirstName << " " << JMBG << " " << PhoneNumber << Birthday.format_in_string();
    }
} Radnik;
typedef struct RadnikIterator {
    int Amount;
    vector<Radnik*> Radnici;

    Radnik* create(int id ,char* firstName, char* lastName, char* jmbg, Datetime bday, char* phoneNumber){
        Radnik* radnik = (Radnik*) malloc(sizeof(Radnik));
        radnik->FirstName = string_merge("",firstName);
        radnik->LastName = string_merge("",lastName);
        radnik->JMBG = string_merge("",jmbg);
        radnik->Birthday = bday;
        radnik->PhoneNumber = string_merge("",phoneNumber);
        radnik->Id = id == -1 ? Amount++ : id;
        
        Radnici.push_back(radnik);

        return radnik;
    }
    Radnik* get_by_id(int Id){
        for(int i=0;i<Radnici.size();i++)
            if(Radnici[i]->Id == Id)
                return Radnici[i];

        return NULL;
    }
    bool remove(int id){
        for(int i=0;i<Radnici.size();i++){
            if(Radnici[i]->Id == id){
                Radnici.erase(Radnici.begin()+i);
                return true;
            }
        }

        return false;
    }
    void save(){
        ofstream radniciData("radnici.txt");
        cout << "sejvam" << endl;

        for(int i=0;i<Radnici.size();i++){
            cout << Radnici[i]->Id << endl;
            radniciData << Radnici[i]->Id << "," << 
                Radnici[i]->FirstName << "," << Radnici[i]->LastName << "," << 
                Radnici[i]->JMBG << "," << Radnici[i]->Birthday.format_in_string() << "," <<
                Radnici[i]->PhoneNumber << endl;
                }

        // Close the file
        radniciData.close();
    }

    void read(){
        ifstream radniciData("radnici.txt");
        if(!radniciData)
            return;

        string readLine;
        
        while (getline (radniciData, readLine)) {
            string buffer = "";
            vector<char*> values;
            for(int i=0;i<readLine.length();i++){
                if(readLine[i] == ',' || i == readLine.length()-1){
                    if(0 < buffer.length())
                        values.push_back(string_to_char(buffer));

                    buffer = "";
                    continue;
                }

                buffer += readLine[i];
            }


            Radnik* radnik = create(
                string_to_int(values[0]),
                values[1],
                values[2],
                values[3],
                construct_from_string(values[4]),
                values[5]
            );
        }

        Amount = Radnici.size() > 0 ? (Radnici[Radnici.size()-1]->Id+1) : 0;

        // Close the file
        radniciData.close();
    }
} RadnikIterator;




//  ██████   ██████  ██████   █████  ██    ██ ██           ██  █████   ██████ 
//  ██   ██ ██    ██ ██   ██ ██   ██ ██    ██ ██           ██ ██   ██ ██      
//  ██   ██ ██    ██ ██████  ███████ ██    ██ ██           ██ ███████ ██      
//  ██   ██ ██    ██ ██   ██ ██   ██  ██  ██  ██      ██   ██ ██   ██ ██      
//  ██████   ██████  ██████  ██   ██   ████   ███████  █████  ██   ██  ██████ 
//                                                                            
//                                                                            

typedef struct Dobavljac
{
    int Id;
    char* Name;
    char* Address;
    char* PhoneNumber;
    char* Email;
    char* FaxNumber;

    void print(){
        cout << "["<<Id<<"] "<<Name<<" "<<Address<<" "<<PhoneNumber<<" "<<Email<<" "<<FaxNumber;
    }

} Dobavljac;
typedef struct DonavljacIterator {
    int Amount;
    vector<Dobavljac*> Dobavljaci;

    Dobavljac* create(int id ,char* name, char* address, char* phone, char* email, char* fax){
        Dobavljac* dobavljac = (Dobavljac*) malloc(sizeof(Dobavljac));
        dobavljac->Name = string_merge("",name);
        dobavljac->Address = string_merge("",address);
        dobavljac->PhoneNumber = string_merge("",phone);
        dobavljac->Email = string_merge("",email);
        dobavljac->FaxNumber = string_merge("",fax);

        dobavljac->Id = id == -1 ? Amount++ : id;
        
        Dobavljaci.push_back(dobavljac);

        return dobavljac;
    }
    Dobavljac* get_by_id(int Id){
        for(int i=0;i<Dobavljaci.size();i++)
            if(Dobavljaci[i]->Id == Id)
                return Dobavljaci[i];

        return NULL;
    }
    bool remove(int id){
        for(int i=0;i<Dobavljaci.size();i++){
            if(Dobavljaci[i]->Id == id){
                Dobavljaci.erase(Dobavljaci.begin()+i);
                return true;
            }
        }

        return false;
    }
    void save(){
        ofstream data("dobavljaci.txt");

        for(int i=0;i<Dobavljaci.size();i++){
            data << Dobavljaci[i]->Id << "," << 
                Dobavljaci[i]->Name << "," << Dobavljaci[i]->Address << "," << 
                Dobavljaci[i]->PhoneNumber << "," << Dobavljaci[i]->Email<< "," <<
                Dobavljaci[i]->FaxNumber << endl;
                }

        // Close the file
        data.close();
    }

    void read(){
        ifstream data("dobavljaci.txt");
        if(!data)
            return;

        string readLine;
        
        while (getline (data, readLine)) {
            string buffer = "";
            vector<char*> values;
            for(int i=0;i<readLine.length();i++){
                if(readLine[i] == ',' || i == readLine.length()-1 || readLine[i] == '\n'){
                    if(0 < buffer.length())
                        values.push_back(string_to_char(buffer));

                    buffer = "";
                    continue;
                }

                buffer += readLine[i];
            }


            create(
                string_to_int(values[0]),
                values[1],
                values[2],
                values[3],
                values[4],
                values[5]
            );
        }

        Amount = Dobavljaci.size() > 0 ? (Dobavljaci[Dobavljaci.size()-1]->Id+1) : 0;

        // Close the file
        data.close();
    }
} DonavljacIterator;




//   █████  ██████  ████████ ██ ██   ██ ██      
//  ██   ██ ██   ██    ██    ██ ██  ██  ██      
//  ███████ ██████     ██    ██ █████   ██      
//  ██   ██ ██   ██    ██    ██ ██  ██  ██      
//  ██   ██ ██   ██    ██    ██ ██   ██ ███████ 
//                                              
//                                              

typedef struct Artikl{
    int Id;
    char* Name;
    double Amount;
    char* Description;
    int DobavljacId;
    double Price;
    double MinAmount;
} Artikl;
typedef struct ArtiklIterator {
    int Amount;
    vector<Artikl*> Artikli;

    Artikl* create(int id ,char* name, double amount, char* description, int dobavljacId, double price, double minAmount){
        Artikl* artikl = (Artikl*) malloc(sizeof(Artikl));
        artikl->Name = string_merge("",name);
        artikl->Amount = amount;
        artikl->Description = string_merge("",description);
        artikl->Price = price;
        artikl->DobavljacId = dobavljacId;
        artikl->MinAmount = minAmount;

        artikl->Id = id == -1 ? Amount++ : id;
        
        Artikli.push_back(artikl);

        return artikl;
    }
    Artikl* get_by_id(int Id){
        for(int i=0;i<Artikli.size();i++)
            if(Artikli[i]->Id == Id)
                return Artikli[i];

        return NULL;
    }
    bool remove(int id){
        for(int i=0;i<Artikli.size();i++){
            if(Artikli[i]->Id == id){
                Artikli.erase(Artikli.begin()+i);
                return true;
            }
        }

        return false;
    }
    void save(){
        ofstream data("artikli.txt");

        for(int i=0;i<Artikli.size();i++){
            data << Artikli[i]->Id << "," << 
                Artikli[i]->Name << "," << Artikli[i]->Amount << "," << 
                Artikli[i]->Description << "," << Artikli[i]->DobavljacId<< "," <<
                Artikli[i]->Price << "," << Artikli[i]->MinAmount << endl;
        }

        data.close();
    }

    void read(){
        ifstream data("artikli.txt");
        if(!data)
            return;

        string readLine;
        
        while (getline (data, readLine)) {
            
            string buffer = "";
            vector<char*> values;
            for(int i=0;i<readLine.length();i++){
                if(readLine[i] == ',' || i == readLine.length()-1 || readLine[i] == '\n'){
                    if((0 < buffer.length() || readLine[i] == ','))
                        values.push_back(string_to_char(buffer));
                    else 
                        if(i == readLine.length()-1 && readLine[i] != '\n'){
                            string temp_elem = "" + readLine[i];
                            values.push_back(string_to_char(temp_elem));
                        }
                    
                    buffer = ""; 
                    continue;
                }

                buffer += readLine[i];
            }

            create(
                string_to_int(values[0]),
                values[1],
                string_to_double(values[2]),
                values[3],
                string_to_int(values[4]),
                string_to_double(values[5]),
                string_to_double(values[6])
            );
        }

        Amount = Artikli.size() > 0 ? (Artikli[Artikli.size()-1]->Id+1) : 0;

        // Close the file
        data.close();
    }

    vector<Artikl*> get_by_dobavljacId(int dobavljacId){
        vector<Artikl*> artikli;
        for(int i=0;i<Artikli.size();i++)
            if(Artikli[i]->DobavljacId == dobavljacId)
                artikli.push_back(Artikli[i]);

        return artikli;
    }
} ArtiklIterator;




//  ███    ██  █████  ██████  ██    ██ ██████       ██ ██████   █████  
//  ████   ██ ██   ██ ██   ██ ██    ██ ██   ██      ██ ██   ██ ██   ██ 
//  ██ ██  ██ ███████ ██████  ██    ██ ██   ██      ██ ██████  ███████ 
//  ██  ██ ██ ██   ██ ██   ██ ██    ██ ██   ██ ██   ██ ██   ██ ██   ██ 
//  ██   ████ ██   ██ ██   ██  ██████  ██████   █████  ██████  ██   ██ 
//                                                                     
//                                                                     

typedef struct Narudjba{
    int Id;
    Datetime CreatedAt;
    Datetime ArrivedAt;
    int Status;
    int DobavljacId;
    int ArtiklId;
    double Amount;
    int RadnikId;

    string status_string(){
        switch(Status){
            case 0:
                return "Potrebno";
                break;

            case 1:
                return "Naruceno";
                break;

            case 2:
                return "Dostavljeno";
                break;

            case 3:
                return "Otkazano";
                break;
        }

        return "Arhivirano";
    }
} Narudzba;
typedef struct NarudzbaIterator{
    int Amount;
    vector<Narudzba*> Narudzbe;

    Narudzba* create(int id ,Datetime createdAt, Datetime arrivedAt, int status, int dobavljacId, int artiklId, double amount, int radnikId){
        Narudzba* narudzba = (Narudzba*) malloc(sizeof(Narudzba));
        narudzba->CreatedAt = createdAt;
        narudzba->ArrivedAt = arrivedAt;
        narudzba->Status = status;
        narudzba->DobavljacId = dobavljacId;
        narudzba->ArtiklId = artiklId;
        narudzba->Amount = amount;
        narudzba->RadnikId = radnikId;

        narudzba->Id = id == -1 ? Amount++ : id;
        
        Narudzbe.push_back(narudzba);

        return narudzba;
    }
    Narudzba* get_by_id(int Id){
        for(int i=0;i<Narudzbe.size();i++)
            if(Narudzbe[i]->Id == Id)
                return Narudzbe[i];

        return NULL;
    }
    bool remove(int id){
        for(int i=0;i<Narudzbe.size();i++){
            if(Narudzbe[i]->Id == id){
                Narudzbe.erase(Narudzbe.begin()+i);
                return true;
            }
        }

        return false;
    }
    void save(){
        ofstream data("narudzbe.txt");

        for(int i=0;i<Narudzbe.size();i++){
            data << Narudzbe[i]->Id << "," << 
                Narudzbe[i]->CreatedAt.format_in_string() << "," << 
                Narudzbe[i]->ArrivedAt.format_in_string() << "," << Narudzbe[i]->Status<< "," <<
                Narudzbe[i]->DobavljacId << "," << Narudzbe[i]->ArtiklId << "," << Narudzbe[i]->Amount << "," << Narudzbe[i]->RadnikId << endl;
        }

        data.close();
    }

    void read(){
        ifstream data("narudzbe.txt");
        if(!data)
            return;

        string readLine;
        
        while (getline (data, readLine)) {
            string buffer = "";
            vector<char*> values;
            for(int i=0;i<readLine.length();i++){
                if(readLine[i] == ',' || i == readLine.length()-1 || readLine[i] == '\n'){
                    if(0 < buffer.length() || readLine[i] == ',')
                        values.push_back(string_to_char(buffer));
                    else
                        if(i == readLine.length()-1 && readLine[i] != '\n'){
                            string temp_elem = "" + readLine[i];
                            values.push_back(string_to_char(temp_elem));
                        }

                    buffer = "";
                    continue;
                }

                buffer += readLine[i];
            }


            create(
                string_to_int(values[0]),
                construct_from_string(values[1]),
                construct_from_string(values[2]),
                string_to_int(values[3]),
                string_to_int(values[4]),
                string_to_int(values[5]),
                string_to_double(values[6]),
                string_to_int(values[7])
            );
        }

        Amount = Narudzbe.size() > 0 ? (Narudzbe[Narudzbe.size()-1]->Id+1) : 0;

        // Close the file
        data.close();
    }
} NarudzbaIterator;



//  ███    ███  ██████  ██████  ███████ ██          ███    ███  █████  ███    ██  █████   ██████  ███████ ██████  
//  ████  ████ ██    ██ ██   ██ ██      ██          ████  ████ ██   ██ ████   ██ ██   ██ ██       ██      ██   ██ 
//  ██ ████ ██ ██    ██ ██   ██ █████   ██          ██ ████ ██ ███████ ██ ██  ██ ███████ ██   ███ █████   ██████  
//  ██  ██  ██ ██    ██ ██   ██ ██      ██          ██  ██  ██ ██   ██ ██  ██ ██ ██   ██ ██    ██ ██      ██   ██ 
//  ██      ██  ██████  ██████  ███████ ███████     ██      ██ ██   ██ ██   ████ ██   ██  ██████  ███████ ██   ██ 
//                                                                                                                
//                                                                                                                

typedef struct ModelsManager{
    RadnikIterator Radnik;
    DonavljacIterator Dobavljac;
    ArtiklIterator Artikl;
    NarudzbaIterator Narudzba;

    void load_data(){
        Radnik.read();
        Dobavljac.read();
        Artikl.read();
        Narudzba.read();
    }
    void save_data(){
        Radnik.save();
        Dobavljac.save();
        Artikl.save();
        Narudzba.save();
    }
} ModelsManager;
ModelsManager Manager;


int enter_option(int min, int max, bool back){
    int option;
    while(true){
        cout << "Opcija: "; option = read_int();
        if(!( (min <= option && option <= max) || (back && option == 0) ))
            cout << "Opcija nije validna!";
        else
            return option;
    }
    
    return option;
}




//  ██████   █████  ██████  ███    ██ ██ ██   ██     ███    ███ ███████ ███    ██ ██    ██ 
//  ██   ██ ██   ██ ██   ██ ████   ██ ██ ██  ██      ████  ████ ██      ████   ██ ██    ██ 
//  ██████  ███████ ██   ██ ██ ██  ██ ██ █████       ██ ████ ██ █████   ██ ██  ██ ██    ██ 
//  ██   ██ ██   ██ ██   ██ ██  ██ ██ ██ ██  ██      ██  ██  ██ ██      ██  ██ ██ ██    ██ 
//  ██   ██ ██   ██ ██████  ██   ████ ██ ██   ██     ██      ██ ███████ ██   ████  ██████  
//                                                                                         
//                                                                                         

void radnik_menu(){
    string ime;
    string prezime;
    string jmbg;
    string phone;
    string bday;
    Radnik* radnik = NULL;
    Datetime datetime;
    int id;

    while(true){
        cout << "##################################################################" << endl;
        cout << "Opcije radnika." << endl;
        cout << "Opcije:" << endl;
        cout << "   [0] Natrag" << endl;
        cout << "   [1] Novi Radnik" << endl;
        cout << "   [2] Uredi Radnika" << endl;
        cout << "   [3] Izbrisi Radnika" << endl;
        cout << "   [4] Izlistaj Radnike" << endl;
        cout << "   [5] Detalji Radnika" << endl;

        switch(enter_option(0,6,true)){
            case 0:
                return;
                break;

            case 1:
                cout << "##################################################################" << endl;
                cout << "Novi radnik." << endl;
                cout << "Ime: "; cin >> ime; cin.ignore(1,'\n');
                cout << "Prezime: "; cin >> prezime; cin.ignore(1,'\n');
                cout << "JMBG: "; cin >> jmbg; cin.ignore(1,'\n');
                cout << "Telefon: "; cin >> phone; cin.ignore(1,'\n');
                cout << "Datum rodenja [dd-mm-gggg]: "; cin >> bday; cin.ignore(1,'\n');
                datetime.format_from_string(string_merge( string_to_char(bday) ," 00:00:00"));

                Manager.Radnik.create(
                    -1,
                    string_to_char(ime),
                    string_to_char(prezime),
                    string_to_char(jmbg),
                    datetime,
                    string_to_char(phone)
                );
                break;

            case 2:
                cout << "##################################################################" << endl;
                cout << "Uredi radnik." << endl;
                cout << "Unesi ID radnika: "; cin >> id; cin.ignore(1,'\n');
                
                radnik = Manager.Radnik.get_by_id(id);
                radnik->print(); cout << endl;

                cout << "Ime: "; cin >> ime; cin.ignore(1,'\n');
                cout << "Prezime: "; cin >> prezime; cin.ignore(1,'\n');
                cout << "JMBG: "; cin >> jmbg; cin.ignore(1,'\n');
                cout << "Telefon: "; cin >> phone; cin.ignore(1,'\n');

                cout << "Datum rodjenja [dd-mm-gggg]: "; cin >> bday; cin.ignore(1,'\n');
                datetime.format_from_string(string_merge(string_to_char(bday)," 00:00:00"));


                radnik->FirstName = string_to_char(ime);
                radnik->LastName = string_to_char(prezime);
                radnik->JMBG = string_to_char(jmbg);
                radnik->PhoneNumber = string_to_char(phone);
                radnik->Birthday = datetime;
                break;

            case 3:
                cout << "##################################################################" << endl;
                cout << "Izbrisi radnik." << endl;
                cout << "Unesi ID radnika: "; cin >> id; cin.ignore(1,'\n');
                Manager.Radnik.remove(id);
                break;

            case 4:
                cout << "##################################################################" << endl;
                cout << "Lista radnika." << endl;

                for(int i=0;i<Manager.Radnik.Radnici.size();i++)
                    cout << "[" << Manager.Radnik.Radnici[i]->Id << "] " << Manager.Radnik.Radnici[i]->LastName << " " << Manager.Radnik.Radnici[i]->FirstName << endl;
                break;
                
            case 5:
                cout << "##################################################################" << endl;
                cout << "Detalji radnika." << endl;
                cout << "Unesi ID radnika: "; cin >> id; cin.ignore(1,'\n');
                
                Radnik* radnik = Manager.Radnik.get_by_id(id);
                cout << "Ime: " << radnik->FirstName << endl;
                cout << "Prezime: " << radnik->LastName << endl;
                cout << "JMBG: " << radnik->JMBG << endl;
                cout << "Telefon: " << radnik->PhoneNumber << endl;
                cout << "Datum rodjenja: " << radnik->Birthday.format_in_string() << endl;
                break;
        }
    }
}




//  ██████   ██████  ██████   █████  ██    ██ ██           ██  █████   ██████     ███    ███ ███████ ███    ██ ██    ██ 
//  ██   ██ ██    ██ ██   ██ ██   ██ ██    ██ ██           ██ ██   ██ ██          ████  ████ ██      ████   ██ ██    ██ 
//  ██   ██ ██    ██ ██████  ███████ ██    ██ ██           ██ ███████ ██          ██ ████ ██ █████   ██ ██  ██ ██    ██ 
//  ██   ██ ██    ██ ██   ██ ██   ██  ██  ██  ██      ██   ██ ██   ██ ██          ██  ██  ██ ██      ██  ██ ██ ██    ██ 
//  ██████   ██████  ██████  ██   ██   ████   ███████  █████  ██   ██  ██████     ██      ██ ███████ ██   ████  ██████  
//                                                                                                                      
//                                                                                                                      

void dobavljaci_menu(){
    string name;
    string address;
    string phoneNumber;
    string email;
    string faxNumber;
    int id;
    Dobavljac* dobavljac = NULL;

    while(true){
        cout << "##################################################################" << endl;
        cout << "Opcije dobavljaci." << endl;
        cout << "Opcije:" << endl;
        cout << "   [0] Natrag" << endl;
        cout << "   [1] Novi Dobavljac" << endl;
        cout << "   [2] Uredi Dobavljaca" << endl;
        cout << "   [3] Izbrisi Dobavljaca" << endl;
        cout << "   [4] Izlistaj Dobavljaca" << endl;
        cout << "   [5] Detalji Dobavljaca" << endl;


        switch(enter_option(0,5,true)){
            case 0:
                return;
                break;

            case 1:
                cout << "##################################################################" << endl;
                cout << "Novi dobavljac." << endl;
                cout << "Ime: "; name = read_line();
                cout << "Adresa: "; address = read_line();
                cout << "Telefon: "; cin >> phoneNumber; cin.ignore(1,'\n');
                cout << "Email: "; cin >> email; cin.ignore(1,'\n');
                cout << "Fax Number: "; cin >> faxNumber; cin.ignore(1,'\n');

                Manager.Dobavljac.create(
                    -1,
                    string_to_char(name),
                    string_to_char(address),
                    string_to_char(phoneNumber),
                    string_to_char(email),
                    string_to_char(faxNumber)
                );
                break;

            case 2:
                cout << "##################################################################" << endl;
                cout << "Uredi dobavljac." << endl;
                cout << "Unesi ID dobavljaca: "; cin >> id; cin.ignore(1,'\n');


                dobavljac = Manager.Dobavljac.get_by_id(id);
                dobavljac->print(); cout << endl;

                cout << "Ime: "; name = read_line();
                cout << "Adresa: "; address = read_line();
                cout << "Telefon: "; cin >> phoneNumber; cin.ignore(1,'\n');
                cout << "Email: "; cin >> email; cin.ignore(1,'\n');
                cout << "Fax Number: "; cin >> faxNumber; cin.ignore(1,'\n');

                dobavljac->Name = string_to_char(name);
                dobavljac->Address = string_to_char(address);
                dobavljac->PhoneNumber = string_to_char(phoneNumber);
                dobavljac->Email = string_to_char(email);
                dobavljac->FaxNumber = string_to_char(faxNumber);
                break;

            case 3:
                cout << "##################################################################" << endl;
                cout << "Izbrisi dobavljac." << endl;
                cout << "Unesi ID dobavljaca: "; cin >> id; cin.ignore(1,'\n');

                Manager.Dobavljac.remove(id);
                break;

            case 4:
                cout << "##################################################################" << endl;
                cout << "Lista dobavljaca." << endl;
                for(int i=0;i<Manager.Dobavljac.Dobavljaci.size();i++)
                    cout << "[" << Manager.Dobavljac.Dobavljaci[i]->Id << "]: " << Manager.Dobavljac.Dobavljaci[i]->Name << endl;
                break;

            case 5:
                cout << "##################################################################" << endl;
                cout << "Detalji dobavljac." << endl;
                cout << "Unesi ID dobavljaca: "; cin >> id;cin.ignore(1,'\n');

                dobavljac = Manager.Dobavljac.get_by_id(id);
                vector<Artikl*> artikli = Manager.Artikl.get_by_dobavljacId(id);
                cout << "Ime: " << dobavljac->Name << endl;
                cout << "Adresa: " << dobavljac->Address << endl;
                cout << "Telefon: " << dobavljac->PhoneNumber << endl;
                cout << "Email: " << dobavljac->Email << endl;
                cout << "Fax: " << dobavljac->FaxNumber << endl;
                cout << "Broj artikala: " <<  artikli.size() << endl;
                cout << "Artikli: " << endl;
                for(int i=0;i<artikli.size();i++)
                    cout << "[" << artikli[i]->Id << "] " << artikli[i]->Name << " x " << artikli[i]->Amount << endl;
                break;
        }
    }
}




//   █████  ██████  ████████ ██ ██   ██ ██          ███    ███ ███████ ███    ██ ██    ██ 
//  ██   ██ ██   ██    ██    ██ ██  ██  ██          ████  ████ ██      ████   ██ ██    ██ 
//  ███████ ██████     ██    ██ █████   ██          ██ ████ ██ █████   ██ ██  ██ ██    ██ 
//  ██   ██ ██   ██    ██    ██ ██  ██  ██          ██  ██  ██ ██      ██  ██ ██ ██    ██ 
//  ██   ██ ██   ██    ██    ██ ██   ██ ███████     ██      ██ ███████ ██   ████  ██████  
//                                                                                        
//                                                                                        

void artikl_menu(){
    int id;
    string name;
    double amount;
    string description;
    int dobavljacId;
    double price;
    double minAmount;
    Artikl* artikl = NULL;
    Dobavljac* dobavljac = NULL;

    while(true){
        cout << "##################################################################" << endl;
        cout << "Opcije artikl." << endl;
        cout << "Opcije:" << endl;
        cout << "   [0] Natrag" << endl;
        cout << "   [1] Novi Artikl" << endl;
        cout << "   [2] Uredi Artikl" << endl;
        cout << "   [3] Izbrisi Artikl" << endl;
        cout << "   [4] Izlistaj Artikle" << endl;
        cout << "   [5] Detalji Artikla" << endl;
        cout << "   [6] Artikli sa kriticnom kolicinom" << endl;


        switch(enter_option(0,5,true)){
            case 0:
                return;
                break;

            case 1:
                cout << "##################################################################" << endl;
                cout << "Novi artikl." << endl;
                cout << "Ime: "; name = read_line();
                cout << "Opis: "; description = read_line();
                cout << "Kolicina: "; cin >> amount; cin.ignore(1,'\n');
                cout << "Minimalna kolicina: "; cin >> minAmount;cin.ignore(1,'\n');
                cout << "ID Dobavljaca: "; cin >> dobavljacId;cin.ignore(1,'\n');
                cout << "Cijena: "; cin >> price;cin.ignore(1,'\n');

                Manager.Artikl.create(
                    -1,
                    string_to_char(name),
                    amount,
                    string_to_char(description),
                    dobavljacId,
                    price,
                    minAmount
                );
                break;

            case 2:
                cout << "##################################################################" << endl;
                cout << "Uredi artikl." << endl;
                cout << "Unesi ID artikla: "; cin >> id;cin.ignore(1,'\n');


                artikl = Manager.Artikl.get_by_id(id);
                cout << "Ime: "; name = read_line();
                cout << "Kolicina: "; cin >> amount;cin.ignore(1,'\n');
                cout << "Minimalna kolicina: "; cin >> minAmount;cin.ignore(1,'\n');
                cout << "ID Dobavljaca: "; cin >> dobavljacId;cin.ignore(1,'\n');
                cout << "Cijena: "; cin >> price;cin.ignore(1,'\n');


                artikl->Name = string_to_char(name);
                artikl->Amount = amount;
                artikl->DobavljacId = dobavljacId;
                artikl->Description = string_to_char(description);
                artikl->Price = price;
                artikl->MinAmount = minAmount;
                break;

            case 3:
                cout << "##################################################################" << endl;
                cout << "Izbrisi artikl." << endl;
                cout << "Unesi ID artikla: "; cin >> id;cin.ignore(1,'\n');

                Manager.Artikl.remove(id);
                break;

            case 4:
                cout << "##################################################################" << endl;
                cout << "Lista artikala." << endl;
                for(int i=0;i<Manager.Artikl.Artikli.size();i++)
                    cout << "[" << Manager.Artikl.Artikli[i]->Id << "]: " << Manager.Artikl.Artikli[i]->Name << " x " <<  Manager.Artikl.Artikli[i]->Amount << endl;
                break;

            case 5:
                cout << "##################################################################" << endl;
                cout << "Detalji artikla." << endl;
                cout << "Unesi id artikla: "; cin >> id;cin.ignore(1,'\n');

                artikl = Manager.Artikl.get_by_id(id);
                
                cout << "Ime: " << artikl->Name << endl;
                cout << "Opis: " << artikl->Description << endl;
                cout << "Kolicina: " << artikl->Amount << endl;
                cout << "Minimalna kolicina: " << artikl->MinAmount << endl;
                cout << "Cijena: " << artikl->Price << endl;
                
                
                dobavljac = Manager.Dobavljac.get_by_id(artikl->DobavljacId);
                
                cout << "Dobavljac: " << endl;
                cout << "    Id: " <<  dobavljac->Id << endl;
                cout << "    Ime: " << dobavljac->Name << endl;
                break;

            case 6:
                cout << "##################################################################" << endl;
                cout << "Artikli sa kriticnom kolicinom." << endl;

                for(int i =0;i<Manager.Artikl.Artikli.size();i++){
                    if(Manager.Artikl.Artikli[i]->Amount <= Manager.Artikl.Artikli[i]->MinAmount){
                        dobavljac = Manager.Dobavljac.get_by_id(Manager.Artikl.Artikli[i]->DobavljacId);

                        cout << "["<<Manager.Artikl.Artikli[i]->Id << "] " << Manager.Artikl.Artikli[i]->Name << endl;
                        cout << "   Trenutna kolicina: " << Manager.Artikl.Artikli[i]->Amount << endl;
                        cout << "   Minimalna kolicina: " << Manager.Artikl.Artikli[i]->MinAmount << endl;
                        cout << "   Dobavljac Id: " << dobavljac->Id << endl;
                        cout << "   Naziv dobavljaca: " << dobavljac->Name << endl;
                        cout << "   Kontakt dobavljaca:" << endl;
                        cout << "      Telefon: " << dobavljac->PhoneNumber << endl;
                        cout << "      Fax: " << dobavljac->FaxNumber << endl;
                        cout << "      Email: " << dobavljac->Email << endl;
                        cout << endl;
                    }
                }
                break;
        }
    }
}



//  ███    ██  █████  ██████  ██    ██ ██████       ██ ██████   █████      ███    ███ ███████ ███    ██ ██    ██ 
//  ████   ██ ██   ██ ██   ██ ██    ██ ██   ██      ██ ██   ██ ██   ██     ████  ████ ██      ████   ██ ██    ██ 
//  ██ ██  ██ ███████ ██████  ██    ██ ██   ██      ██ ██████  ███████     ██ ████ ██ █████   ██ ██  ██ ██    ██ 
//  ██  ██ ██ ██   ██ ██   ██ ██    ██ ██   ██ ██   ██ ██   ██ ██   ██     ██  ██  ██ ██      ██  ██ ██ ██    ██ 
//  ██   ████ ██   ██ ██   ██  ██████  ██████   █████  ██████  ██   ██     ██      ██ ███████ ██   ████  ██████  
//                                                                                                               
//                                     
void narudzba_menu(){
    int id;
    string createdAt;
    string arrivedAt;
    int artiklId;
    double amount;
    int radnikId;
    int counter = 0;
    Datetime current = get_current_datetime();
    Narudzba* narudzba = NULL;

    while(true){
        cout << "##################################################################" << endl;
        cout << "Opcije narudzbe." << endl;
        cout << "Opcije:" << endl;
        cout << "   [0] Natrag" << endl;
        cout << "   [1] Nova Narudzba" << endl;
        cout << "   [2] Otkazi Narudzbu" << endl;
        cout << "   [3] Dostavi Narudzbu" << endl;
        cout << "   [4] Generisi Narudzbe" << endl;
        cout << "   [5] Posalji Narudzbe" << endl;
        cout << "   [6] Arhiviraj dostavljenje narudzbe" << endl;
        cout << "   [7] Lista aktivnih narudzbi" << endl;

        switch(enter_option(0,11,true)){
            case 0:
                return;
                break;

            case 1:
                cout << "##################################################################" << endl;
                cout << "Nova narudzba." << endl;
                cout << "Datum stvaranja [dd-mm-gggg]: "; cin >> createdAt; cin.ignore(1,'\n');
                cout << "ID Artikla: "; cin >> artiklId; cin.ignore(1,'\n');
                cout << "Kolicina: "; cin >> amount; cin.ignore(1,'\n');
                cout << "Id radnika koji stvara narudzbu: "; cin >> radnikId;cin.ignore(1,'\n');


                Manager.Narudzba.create(
                    -1,
                    construct_from_string(string_merge(string_to_char(createdAt), " 00:00:00")),
                    construct_from_string(string_merge(string_to_char(createdAt), " 00:00:00")),
                    1,
                    Manager.Artikl.get_by_id(artiklId)->DobavljacId,
                    artiklId,
                    amount,
                    radnikId
                );
                break;

            case 2:
                cout << "##################################################################" << endl;
                cout << "Otkazi Narudzbu" << endl;
                cout << "Unesi ID narudzbe: "; cin >> id;cin.ignore(1,'\n');
                
                narudzba = Manager.Narudzba.get_by_id(id);
                narudzba->Status = 3;
                break;

            case 3:
                cout << "##################################################################" << endl;
                cout << "Dostavi Narudzbu." << endl;
                cout << "Unesi ID narudzbe: "; cin >> id;cin.ignore(1,'\n');
                
                narudzba = Manager.Narudzba.get_by_id(id);
                cout << "Datum dolaska narudzbe[dd-mm-gggg]: "; cin >> createdAt;cin.ignore(1,'\n');
                narudzba->ArrivedAt = construct_from_string(string_merge(string_to_char(createdAt), " 00:00:00"));
                narudzba->Status = 2;

                Manager.Artikl.get_by_id(narudzba->ArtiklId)->Amount += narudzba->Amount;
                break;

            case 4:
                cout << "##################################################################" << endl;
                cout << "Generisi Narudzbe." << endl;
                counter = 0;

                for(int i=0;i<Manager.Artikl.Artikli.size();i++){
                    if(Manager.Artikl.Artikli[i]->MinAmount > Manager.Artikl.Artikli[i]->Amount){
                        counter++;
                        Manager.Narudzba.create(
                            -1,
                            current,
                            current,
                            0,
                            Manager.Artikl.Artikli[i]->DobavljacId,
                            Manager.Artikl.Artikli[i]->Id,
                            (Manager.Artikl.Artikli[i]->MinAmount - Manager.Artikl.Artikli[i]->Amount)*2,
                            -1
                        );
                        }
                }
                cout << "   Generisano " << counter << " narudzbi" << endl;
                break;
                
            case 5:
                cout << "##################################################################" << endl;
                cout << "Posalji Narudzbe." << endl;
                counter = 0;

                for(int i=0;i<Manager.Narudzba.Narudzbe.size();i++){
                    if(Manager.Narudzba.Narudzbe[i]->Status == 0){
                        counter++;
                        Manager.Narudzba.Narudzbe[i]->Status = 1;
                        Manager.Narudzba.Narudzbe[i]->RadnikId = id;
                    }
                }
                cout << "   Poslano " << counter << " narudzbi" << endl;
                break;

            case 6:
                cout << "##################################################################" << endl;
                cout << "Arhiviraj dostavljenje narudzbe." << endl;
                counter++;

                for(int i=0;i<Manager.Narudzba.Narudzbe.size();i++){
                    if(Manager.Narudzba.Narudzbe[i]->Status == 2){
                        Manager.Narudzba.Narudzbe[i]->Status = 4;
                        counter++;
                    }
                }
                cout << "   Arhivirano " << counter << " narudzbi" << endl;
                break;

            case 7:
                cout << "##################################################################" << endl;
                cout << "Lista aktivnih narudzbi." << endl;
                counter++;

                for(int i=0;i<Manager.Narudzba.Narudzbe.size();i++){
                    if(Manager.Narudzba.Narudzbe[i]->Status == 1){
                        cout << "[" << Manager.Narudzba.Narudzbe[i]->Id << "] " << 
                            Manager.Artikl.get_by_id(Manager.Narudzba.Narudzbe[i]->ArtiklId)->Name << " x " <<
                            Manager.Narudzba.Narudzbe[i]->Amount << endl; 
                        counter++;
                    }
                }
                cout << "Aktivno " << counter << " narudzbi" << endl;
                break;
        }
    }
}



//  ███    ███  █████  ██ ███    ██     ███████ ██    ██ ███    ██ ██   ██  ██████ ██      ██  █████  
//  ████  ████ ██   ██ ██ ████   ██     ██      ██    ██ ████   ██ ██  ██  ██      ██      ██ ██   ██ 
//  ██ ████ ██ ███████ ██ ██ ██  ██     █████   ██    ██ ██ ██  ██ █████   ██      ██      ██ ███████ 
//  ██  ██  ██ ██   ██ ██ ██  ██ ██     ██      ██    ██ ██  ██ ██ ██  ██  ██      ██ ██   ██ ██   ██ 
//  ██      ██ ██   ██ ██ ██   ████     ██       ██████  ██   ████ ██   ██  ██████ ██  █████  ██   ██ 
//                                                                                                    
//                                                                                                    

int main(){
    Manager.load_data();

    cout << "Dobro dosli u sistemsku konzolu." << endl;
    while(true){
        cout << "Opcije:" << endl;
        cout << "   [0] Izlaz" << endl;
        cout << "   [1] Radnici" << endl;
        cout << "   [2] Dobavljaci" << endl;
        cout << "   [3] Artikli" << endl;
        cout << "   [4] Narudzbe" << endl;
        cout << endl << endl << "Opcija: ";

        switch (enter_option(0,4,true))
        {
            case 0:
                Manager.save_data();
                return 0;
                break;
            
            case 1:
                radnik_menu();
                break;

            case 2:
                dobavljaci_menu();
                break;

            case 3:
                artikl_menu();
                break;
            case 4:
                narudzba_menu();
                break;
        }
    }
}
