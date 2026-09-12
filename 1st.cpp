#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SoilSensor{
    private:
        string sensorld;
        double moistureLevel;
        string timestamp;

    public:
        SoilSensor(string id,double moisture,string time)
            :sensorld(id),moistureLevel(moisture),timestamp(time){}

        void readSensor(double newMoisture,string newTime){
            moistureLevel = newMoisture;
            timestamp = newTime;
        }

        void DisplayData()const{
            cout<<"Sensor:"<<sensorld<<"| Moisture :"<<moistureLevel<<"%"<<"| Time:"<<timestamp<<endl;

        }

};

int main(){
    vector<SoilSensor> farmSensors;
    farmSensors.emplace_back("S001",45.2,"08:00");
    farmSensors.emplace_back("S002",55.2,"08:00");
    farmSensors.emplace_back("S003",84.2,"08:00");

    cout<<"===Morning Sensor Readings ===="<<endl;
    for(const auto& sensor:farmSensors){
        sensor.DisplayData();
    }

    farmSensors[0].readSensor(47.5,"09:00");
    cout<<"\n ===Updated reading ==="<<endl;
    farmSensors[0].DisplayData();
}