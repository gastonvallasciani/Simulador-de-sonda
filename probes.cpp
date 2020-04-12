#include "probes.h"

// Metodo Constructor
probes::probes(float waterLevel_, float productLevel_, float temperature_, char errorStatus_, int probeLength_, bool probeType_, int id_)
{
    waterLevel   = waterLevel_;
    productLevel = productLevel_;
    temperature  = temperature_;
    errorStatus  = errorStatus_;
    probeLength  = probeLength_;
    probeType    = probeType_;
    id           = id_;
}

// Metodo Destructor
probes::~probes()
{

}

// Metodo Constructor: Setters
void probes::setWaterLevel(float waterLevel_)
{
    waterLevel = waterLevel_;
}

void probes::setProductLevel(float productLevel_)
{
    productLevel = productLevel_;
}

void probes::setTemperature(float temperature_)
{
    temperature = temperature_;
}

void probes::setErrorStatus(char errorStatus_)
{
    errorStatus = errorStatus_;
}

void probes::setProbeLength(int probeLength_)
{
    probeLength = probeLength_;
}

void probes::setProbeType(bool probeType_)
{
    probeType = probeType_;
}

void probes::setProbeId(int id_)
{
    id = id_;
}

// Metodo Constructor: Getters
float probes::getWaterLevel(void)
{
    return(waterLevel);
}

float probes::getProductLevel(void)
{
    return(productLevel);
}

float probes::getTemperature(void)
{
    return(temperature);
}

char probes::getErrorStatus(void)
{
    return(errorStatus);
}

int probes::getProbeLength()
{
    return(probeLength);
}

bool probes::getProbeType()
{
    return(probeType);
}

int probes::getProbeId()
{
    return(id);
}
