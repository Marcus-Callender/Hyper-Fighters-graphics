// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "GameFramework/Pawn.h"
#include "BP_Terry.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(MyLogCategory, Log, All);

UCLASS()
class HYPERFIGHTERSGRAPHIC_API ABP_Terry : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABP_Terry();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


};

enum eResult
{
	SP_LOSE,
	LOSE,
	WIN,
	SP_WIN
};

enum eType
{
	L_ATTACK,
	H_ATTACK,
	THROW,
	BLOCK,
	DODGE
};

class C_FighterData
{
public:

	C_FighterData();
	~C_FighterData();

	bool isKOd();
	void knockDown();
	void gainHp(int ammount);
	virtual void rest();
	int getHp();
	int getPreviousHp();
	int getFocus();
	int getPreviousFocus();
	int& getFocusRef();
	virtual void takeDamage(int ammount, bool gainMeter = true);
	std::string getName();
	virtual bool canUseHyperSkill();
	void addToName(std::string add);
	bool getKnockedDown();
	virtual void useHyper();
	void takeFocusDamage(int ammount);
	virtual void gainFocus(int ammount);
	//void giveStatus(C_Status* pStatus);
	//void removeStatus(int z);
	//C_Status* getStatus(int z);

	virtual void reciveCustomData(void* data);

protected:

	int m_hp;
	int m_previousHP;
	//int m_maxHP;
	std::string m_name;
	int m_focus;
	int m_maxFocus;
	int m_previousFocus;
	bool m_knockedDown;
	//void* m_pStatus;
	//C_Status* m_pStatuses[3];
};

class C_Move
{
	C_Move(int damage, float speed, bool knockDown, double focusGain, std::string name, C_FighterData * pMe);
	~C_Move();

	virtual eResult use(C_FighterData* vs, C_Move* vsMove) = 0;
	virtual void win(C_FighterData* vs, C_Move* vsMove) = 0;
	virtual void lose(C_FighterData* vs, C_Move* vsMove) = 0;

	std::string getInfo();
	int	getDamage();
	virtual float getSpeed();
	eType getType();

protected:
	int m_damage;
	float m_speed;
	bool m_knockDown;
	double m_FocusGain;
	std::string m_name;
	eType m_type;
	C_FighterData* m_pMe;
};

