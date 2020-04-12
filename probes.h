#ifndef PROBES_H
#define PROBES_H

#define NO_ERROR         0
#define INTERNAL_ERROR   1
#define COMM_ERROR       2

#define MASTER           0
#define SLAVE            1

#define ID_MAX           18

class probes
{
// Atributos
private:
    float waterLevel   = 0;
    float productLevel = 0;
    float temperature  = 0;
    char  errorStatus  = NO_ERROR;
    int   probeLength  = 1000;
    bool  probeType    = MASTER;
    int   id           = 0;
// Metodos
public:
// Constructor
    probes(float waterLevel_, float productLevel_, float temperature_, char errorStatus_, int probeLength_, bool probeType_, int id_);
// Destructor
    ~probes();
// Setters
    void setWaterLevel(float waterLevel_);
    void setProductLevel(float productLevel_);
    void setTemperature(float temperature_);
    void setErrorStatus(char errorStatus_);
    void setProbeLength(int probeLength_);
    void setProbeType(bool probeType_);
    void setProbeId(int id_);
// Getters
    float getWaterLevel(void);
    float getProductLevel(void);
    float getTemperature(void);
    char getErrorStatus(void);
    int getProbeLength(void);
    bool getProbeType(void);
    int getProbeId(void);
};

#endif // PROBES_H
