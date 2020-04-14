#include "probes.h"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Constructor

probes::probes(float waterLevel_, float productLevel_, float temperature_,
               probeError_t errorStatus_, int probeLength_,
               probeType_t probeType_, int id_, probeBrand_t probeBrand_)
{
    waterLevel   = waterLevel_;
    productLevel = productLevel_;
    temperature  = temperature_;
    errorStatus  = errorStatus_;
    probeLength  = probeLength_;
    probeType    = probeType_;
    id           = id_;
    probeBrand   = probeBrand_;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Destructor

probes::~probes()
{

}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
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

void probes::setErrorStatus(probeError_t errorStatus_)
{
    errorStatus = errorStatus_;
}

void probes::setProbeLength(int probeLength_)
{
    probeLength = probeLength_;
}

void probes::setProbeType(probeType_t probeType_)
{
    probeType = probeType_;
}

void probes::setProbeId(int id_)
{
    id = id_;
}

void probes::setProbeBrand(probeBrand_t probeBrand_)
{
    probeBrand = probeBrand_;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
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

probeError_t probes::getErrorStatus(void)
{
    return(errorStatus);
}

int probes::getProbeLength()
{
    return(probeLength);
}

probeType_t probes::getProbeType()
{
    return(probeType);
}

int probes::getProbeId()
{
    return(id);
}

probeBrand_t probes::getProbeBrand()
{
    return(probeBrand);
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
