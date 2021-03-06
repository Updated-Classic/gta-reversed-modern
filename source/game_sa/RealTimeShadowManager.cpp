#include "StdInc.h"

#include "RealTimeShadowManager.h"

CRealTimeShadowManager& g_realTimeShadowMan = *(CRealTimeShadowManager*)0xC40350;

void CRealTimeShadowManager::Init() {
    plugin::CallMethod<0x7067C0, CRealTimeShadowManager*>(this);
}

void CRealTimeShadowManager::Exit() {
    plugin::CallMethod<0x706A60, CRealTimeShadowManager*>(this);
}

void CRealTimeShadowManager::ReInit() {
    plugin::CallMethod<0x706870, CRealTimeShadowManager*>(this);
}

void CRealTimeShadowManager::Update() {
    plugin::CallMethod<0x706AB0, CRealTimeShadowManager*>(this);
}

CRealTimeShadow& CRealTimeShadowManager::GetRealTimeShadow(CPhysical* physical) {
    return plugin::CallMethodAndReturn<CRealTimeShadow&, 0x706970, CRealTimeShadowManager*, CPhysical*>(this, physical);
}

void CRealTimeShadowManager::DoShadowThisFrame(CPhysical* physical) {
    plugin::CallMethod<0x706BA0, CRealTimeShadowManager*, CPhysical*>(this, physical);
}

void CRealTimeShadowManager::ReturnRealTimeShadow(CRealTimeShadow* pShadow) {
    plugin::CallMethod<0x705B30, CRealTimeShadowManager*, CRealTimeShadow*>(this, pShadow);
}
