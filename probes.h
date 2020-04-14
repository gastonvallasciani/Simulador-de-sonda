#ifndef PROBES_H
#define PROBES_H

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// Probe id: ID_MAX
#define ID_MAX           18

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// Probe types
typedef  enum{
    WIRED          = 0,
    WIRELESS       = 1
}probeType_t;

// Probe errors
typedef enum{
    NO_ERROR       = 0,
    INTERNAL_ERROR = 1,
    COMM_ERROR     = 2
}probeError_t;

// Probe brand types:
typedef enum{
    GENERIC        = 0,
    AMETEK         = 1,
    WAYNE          = 2
}probeBrand_t;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

class probes
{
// Atributos
private:
    float waterLevel          = 0;
    float productLevel        = 0;
    float temperature         = 0;
    probeError_t  errorStatus = NO_ERROR;
    int   probeLength         = 1000;
    probeType_t  probeType    = WIRED;
    int   id                  = 0;
    probeBrand_t   probeBrand = GENERIC;
// Metodos
public:
// Constructor
    probes(float waterLevel_, float productLevel_, float temperature_, probeError_t errorStatus_, int probeLength_, probeType_t probeType_, int id_, probeBrand_t probeBrand_);
// Destructor
    ~probes();
// Setters
    void setWaterLevel(float waterLevel_);
    void setProductLevel(float productLevel_);
    void setTemperature(float temperature_);
    void setErrorStatus(probeError_t errorStatus_);
    void setProbeLength(int probeLength_);
    void setProbeType(probeType_t probeType_);
    void setProbeId(int id_);
    void setProbeBrand(probeBrand_t probeBrand_);
// Getters
    float getWaterLevel(void);
    float getProductLevel(void);
    float getTemperature(void);
    probeError_t getErrorStatus(void);
    int getProbeLength(void);
    probeType_t getProbeType(void);
    int getProbeId(void);
    probeBrand_t getProbeBrand(void);
};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif // PROBES_H
