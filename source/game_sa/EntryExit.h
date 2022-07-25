/*
    Plugin-SDK file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "Rect.h"
#include "Vector.h"

class CObject;
class CPed;
class CEntryExit;

class CEntryExit {
public:
    enum eFlags {
        UNKNOWN_INTERIOR       = 1 << 0,
        UNKNOWN_PAIRING        = 1 << 1,
        CREATE_LINKED_PAIR     = 1 << 2,
        REWARD_INTERIOR        = 1 << 3,
        USED_REWARD_ENTRANCE   = 1 << 4,
        CARS_AND_AIRCRAFT      = 1 << 5,
        BIKES_AND_MOTORCYCLES  = 1 << 6,
        DISABLE_ON_FOOT        = 1 << 7,

        ACCEPT_NPC_GROUP       = 1 << 8,
        FOOD_DATE_FLAG         = 1 << 9,
        UNKNOWN_BURGLARY       = 1 << 10,
        DISABLE_EXIT           = 1 << 11,
        BURGLARY_ACCESS        = 1 << 12,
        ENTERED_WITHOUT_EXIT   = 1 << 13,
        ENABLE_ACCESS          = 1 << 14,
        DELETE_ENEX            = 1 << 15,
    };

    char    m_szName[8];
    CRect   m_recEntrance;
    float   m_fEntranceZ;
    float   m_fEntranceAngle; // In radians
    CVector m_vecExitPos;
    float   m_fExitAngle;    // In degrees

    // R* Originally used enum flags, not bitfields.
    // Source: See 0x43F1C9 - The compiler always uses branchless set/unsets for bitfields, this was hand-written.
    union {
        struct {
            uint16 bUnknownInterior : 1;
            uint16 bUnknownPairing : 1;
            uint16 bCreateLinkedPair : 1;
            uint16 bRewardInterior : 1;
            uint16 bUsedRewardEntrance : 1;
            uint16 bCarsAndAircraft : 1;
            uint16 bBikesAndMotorcycles : 1;
            uint16 bDisableOnFoot : 1;

            uint16 bAcceptNpcGroup : 1;
            uint16 bFoodDateFlag : 1;
            uint16 bUnknownBurglary : 1;
            uint16 bDisableExit : 1;
            uint16 bBurglaryAccess : 1;
            uint16 bEnteredWithoutExit : 1;
            uint16 bEnableAccess : 1;
            uint16 bDeleteEnex : 1;
        };
        uint16 m_nFlags{};
    };
    uint8       m_nArea; // eAreaCodes?
    uint8       m_nSkyColor;
    uint8       m_nTimeOn;
    uint8       m_nTimeOff;
    uint8       m_nNumberOfPeds;
    CEntryExit* m_pLink;

    static bool& ms_bWarping;
    static CObject*& ms_pDoor;
    static CEntryExit*& ms_spawnPoint;

public:
    static void InjectHooks();

    void GenerateAmbientPeds(const CVector& posn);
    CEntryExit* GetEntryExitToDisplayNameOf();
    void GetPositionRelativeToOutsideWorld(CVector& outPos);
    bool IsInArea(const CVector& position);
    void RequestAmbientPeds();
    void RequestObjectsInFrustum() const;
    bool TransitionFinished(CPed* ped);
    bool TransitionStarted(CPed* ped);
    void WarpGangWithPlayer(CPed* ped);
    void ProcessStealableObjects(CPed* ped);
    void FindValidTeleportPoint(CVector* point);
    [[nodiscard]] const CRect& GetEntranceRect() const;
    [[nodiscard]] CVector GetPosition() const;
    [[nodiscard]] CVector2D GetPosition2D() const;
    [[nodiscard]] uint8 GetMyOrLinkedArea() const;
};

VALIDATE_SIZE(CEntryExit, 0x3C);
