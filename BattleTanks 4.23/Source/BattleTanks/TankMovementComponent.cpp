// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* leftTrack, UTankTrack* rightTrack)
{
	m_pLeftTrack = leftTrack;
	m_pRightTrack = rightTrack;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super as we are replacing its functionality
	FVector vTankForwardVec = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector vAIForrwardIntention = MoveVelocity;

	float vIntendedMove = FVector::DotProduct(vAIForrwardIntention, vTankForwardVec);
	IntendMoveForward(vIntendedMove);
}

void UTankMovementComponent::IntendMoveForward(float fThrow)
{
	if (!m_pLeftTrack || !m_pRightTrack)
	{
		return;
	}

	m_pLeftTrack->SetThrottle(fThrow);
	m_pRightTrack->SetThrottle(fThrow);
}

void UTankMovementComponent::IntendTurnRight(float fThrow)
{
	if (!m_pLeftTrack || !m_pRightTrack)
	{
		return;
	}

	m_pLeftTrack->SetThrottle(fThrow);
	m_pRightTrack->SetThrottle(-fThrow);
}