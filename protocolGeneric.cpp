#include "protocolGeneric.h"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Constructor

protocolGeneric::protocolGeneric(parseState_t  parseActualState, int activeId)
{
    this->parseActualState = parseActualState;
    this->activeId         = activeId;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodo Destructor

protocolGeneric::~protocolGeneric()
{

}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Setters
void protocolGeneric::setParseActualState(parseState_t  parseActualState_)
{
    parseActualState = parseActualState_;
}

void protocolGeneric::setActiveId(int activeId)
{
    this->activeId = activeId;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Getters

parseState_t protocolGeneric::getParseActualState(void)
{
    return(parseActualState);
}

int protocolGeneric::getActiveId(void)
{
  return(this->activeId);
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Metodos
int protocolGeneric::parseReceivedData(QByteArray dataReceived)
{
    switch(parseActualState)
    {
        case PARSE_P:
        if(dataReceived == "P")
        {
            parseActualState = PARSE_1;
        }
        break;
        case PARSE_1:
        if(dataReceived == "1")
        {
            parseActualState = PARSE_0;
        }
        else
        {
            parseActualState = PARSE_P;
        }
        break;
        case PARSE_0:
        if(dataReceived == "0")
        {
            parseActualState = PARSE_01;
        }
        else
        {
            parseActualState = PARSE_P;
        }
        break;
        case PARSE_01:
        if(dataReceived == "0")
        {
            parseActualState = PARSE_ID1;
        }
        else
        {
            parseActualState = PARSE_P;
        }
        break;

        break;
        case PARSE_ID1:
            IdReceived = dataReceived;
            parseActualState = PARSE_ID2;
        break;
        case PARSE_ID2:
            IdReceived.insert(1,dataReceived);
            // Falta convertir la variable activeId de int a string para poder compararla con el id recibido
            // y luego devolver un 1 para enviar la respuesta del mensaje de la sonda.
            // La respuesta por serial esta probada y funciona bien.
 //           if(IdReceived == activeId)
 //           {
 //               return(1);
 //           }
            parseActualState = PARSE_P;
        break;
    }
    return(0);
}


