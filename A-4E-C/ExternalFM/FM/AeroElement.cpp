#pragma once
#include "AeroElement.h"

Skyhawk::AeroElement::AeroElement
(
	AircraftState& state,
	Table& CLalpha,
	Table& CDalpha,
	Vec3 cp,
	Vec3 surfaceNormal,
	double MAC,
	double area
) :
	m_state{ state },
	m_CLalpha{ CLalpha },
	m_CDalpha{ CDalpha },
	m_cp{ cp },
	m_surfaceNormal{ surfaceNormal },
	m_MAC{ MAC },
	m_area{ area },
	m_dragFactor{ 1.0 },
	m_liftFactor{ 1.0 }
{

}

Skyhawk::AeroElement::~AeroElement()
{

}

void Skyhawk::AeroElement::zeroInit()
{
	m_dragFactor = 1.0;
	m_liftFactor = 1.0;
	m_scalarAirspeed = 0.0;
	m_aoa = 0.0;
	m_beta = 0.0;
	m_kElem = 0.0;
	m_damageElem = 1.0f;

	m_airspeed = Vec3();
	m_liftVec = Vec3();
	m_dragVec = Vec3();
	m_LDwindAxes = Vec3();
	m_RForceElement = Vec3();
	m_moment = Vec3();
}
void Skyhawk::AeroElement::coldInit()
{

}
void Skyhawk::AeroElement::hotInit()
{

}
void Skyhawk::AeroElement::airborneInit()
{

}

void Skyhawk::AeroElement::elementLift()
{
	m_LDwindAxes.y = m_kElem * ( m_CLalpha(m_aoa) * m_liftFactor * m_damageElem );
}

void Skyhawk::AeroElement::elementDrag()
{
	m_LDwindAxes.x = -m_kElem * ( m_CDalpha(m_aoa) * m_dragFactor );
}

void Skyhawk::AeroElement::calculateElementPhysics()
{

	m_airspeed = m_state.getLocalAirspeed() + cross(m_state.getOmega(), m_cp);
	m_dragVec = -normalize(m_airspeed);

	Vec3 tmpNormal{ normalize(cross(m_dragVec, m_surfaceNormal)) };

	m_liftVec = normalize(cross(tmpNormal, m_dragVec));

	m_scalarAirspeed = sqrt(m_airspeed.x * m_airspeed.x + m_airspeed.y * m_airspeed.y + m_airspeed.z * m_airspeed.z);
	m_aoa = atan2(cross(m_surfaceNormal, m_liftVec) * tmpNormal, m_liftVec * m_surfaceNormal);
	m_kElem = pow(m_scalarAirspeed, 2) * m_state.getAirDensity() * m_area * 0.5;
	
	elementLift();
	elementDrag();
	
	//printf("new: LDVec = %lf, %lf, %lf\n", m_LDwindAxes.x, m_LDwindAxes.y, m_LDwindAxes.z);

	m_RForceElement = windAxisToBody(m_LDwindAxes, m_aoa, m_state.getBeta());
	m_moment = cross(m_cp, m_RForceElement);
	
}