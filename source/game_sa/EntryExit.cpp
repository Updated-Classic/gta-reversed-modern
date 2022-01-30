#include "StdInc.h"

void CEntryExit::GetPositionRelativeToOutsideWorld(CVector& positionInOut) {
    return plugin::CallMethod<0x43EA00, CEntryExit*, CVector&>(this, positionInOut);
}
