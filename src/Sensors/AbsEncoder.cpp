#include "AbsEncoder.h"

AbsEncoder::AbsEncoder()
{
    input = 0;
    myAbsEncoder = new SPI(SPI::kOnboardCS0);
    myAbsEncoder->Read(true, (uint8_t*)input, sizeof(input));
}

short AbsEncoder::getInput()
{
    return input;
}
