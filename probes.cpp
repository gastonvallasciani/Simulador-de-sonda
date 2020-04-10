#include "probes.h"

// Metodo Constructor
probes::probes(float waterLevel_, float productLevel_, float temperature_, char errorStatus_, int probeLength_)
{
    waterLevel   = waterLevel_;
    productLevel = productLevel_;
    temperature  = temperature_;
    errorStatus  = errorStatus_;
    probeLength  = probeLength_;
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
