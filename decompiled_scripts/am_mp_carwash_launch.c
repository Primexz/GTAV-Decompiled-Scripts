#region Local Var
	var uLocal_0 = 0;
	var uLocal_1 = 0;
	int iLocal_2 = 0;
	int iLocal_3 = 0;
	int iLocal_4 = 0;
	int iLocal_5 = 0;
	int iLocal_6 = 0;
	int iLocal_7 = 0;
	int iLocal_8 = 0;
	int iLocal_9 = 0;
	int iLocal_10 = 0;
	int iLocal_11 = 0;
	var uLocal_12 = 0;
	var uLocal_13 = 0;
	float fLocal_14 = 0f;
	var uLocal_15 = 0;
	var uLocal_16 = 0;
	int iLocal_17 = 0;
	var uLocal_18 = 0;
	var uLocal_19 = 0;
	var uLocal_20 = 0;
	var uLocal_21 = 0;
	var uLocal_22 = 0;
	char* sLocal_23 = 0;
	var uLocal_24 = 0;
	var uLocal_25 = 0;
	float fLocal_26 = 0f;
	float fLocal_27 = 0f;
	float fLocal_28 = 0f;
	var uLocal_29 = 0;
	var uLocal_30 = 0;
	float fLocal_31 = 0f;
	var uLocal_32 = 0;
	var uLocal_33 = 0;
	var uLocal_34 = 0;
	float fLocal_35 = 0f;
	float fLocal_36 = 0f;
	var uLocal_37 = 0;
	var uLocal_38 = 0;
	int iLocal_39 = 0;
	var uLocal_40 = 0;
	var uLocal_41 = 0;
	var uLocal_42 = 0;
	int iLocal_43 = 0;
	int iLocal_44 = 0;
	int iLocal_45 = 0;
	int iLocal_46 = 0;
	var uLocal_47 = 0;
	var uLocal_48 = 0;
	var uLocal_49 = 0;
	var uScriptParam_0 = 0;
	var uScriptParam_1 = 5;
	var uScriptParam_2 = 0;
	var uScriptParam_3 = 0;
	var uScriptParam_4 = 0;
	var uScriptParam_5 = 0;
	var uScriptParam_6 = 0;
	var uScriptParam_7 = 0;
	var uScriptParam_8 = 0;
	var uScriptParam_9 = 0;
	var uScriptParam_10 = 0;
	var uScriptParam_11 = 0;
	var uScriptParam_12 = 0;
	var uScriptParam_13 = 0;
	var uScriptParam_14 = 0;
	var uScriptParam_15 = 0;
	var uScriptParam_16 = 0;
	var uScriptParam_17 = 5;
	var uScriptParam_18 = 0;
	var uScriptParam_19 = 0;
	var uScriptParam_20 = 0;
	var uScriptParam_21 = 0;
	var uScriptParam_22 = 0;
#endregion

void main() // Position - 0x0
{
	int gameTimer;
	Hash hashKey;
	char* scriptName;
	Vector3 vector;
	int num;

	iLocal_2 = 1;
	iLocal_3 = 134;
	iLocal_4 = 134;
	iLocal_5 = 1;
	iLocal_6 = 1;
	iLocal_7 = 1;
	iLocal_8 = 134;
	iLocal_9 = 1;
	iLocal_10 = 12;
	iLocal_11 = 12;
	fLocal_14 = 0.001f;
	iLocal_17 = -1;
	sLocal_23 = "NULL";
	fLocal_26 = 80f;
	fLocal_27 = 140f;
	fLocal_28 = 180f;
	fLocal_31 = 0f;
	fLocal_35 = -0.0375f;
	fLocal_36 = 0.17f;
	iLocal_39 = 3;
	iLocal_43 = 1;
	iLocal_44 = 65;
	iLocal_45 = 49;
	iLocal_46 = 64;
	hashKey = joaat("carwash1");
	scriptName = "carwash1";
	vector = { uScriptParam_0.f_1[0 /*3*/] };

	if (SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(joaat("am_mp_carwash_launch")) > 1)
		SCRIPT::TERMINATE_THIS_THREAD();

	if (NETWORK::NETWORK_IS_GAME_IN_PROGRESS())
	{
		MISC::NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
		MISC::SET_THIS_SCRIPT_CAN_BE_PAUSED(false);
	}
	else
	{
		SCRIPT::TERMINATE_THIS_THREAD();
	}

	if (Global_2883694)
	{
		if (SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(131838674) == 0)
		{
			SCRIPT::REQUEST_SCRIPT_WITH_NAME_HASH(131838674);
		
			while (!SCRIPT::HAS_SCRIPT_WITH_NAME_HASH_LOADED(131838674))
			{
				SYSTEM::WAIT(0);
			}
		
			SYSTEM::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(131838674, &uScriptParam_0, 23, DEFAULT);
		}
	
		SCRIPT::TERMINATE_THIS_THREAD();
	}

	func_12(PLAYER::PLAYER_PED_ID());
	num = 0;

	while (num == 0)
	{
		if (func_9(PLAYER::PLAYER_ID(), true, false) || func_8() || !func_7(PLAYER::PLAYER_ID()) || func_6() || func_5(PLAYER::PLAYER_ID()) || func_4(PLAYER::PLAYER_ID()) || func_2(PLAYER::PLAYER_ID()))
			num = 0;
		else
			num = 1;
	
		SYSTEM::WAIT(0);
	}

	if (SYSTEM::VDIST2(vector, func_1(157)) < SYSTEM::VDIST2(vector, func_1(156)))
		scriptName = "carwash2";

	gameTimer = MISC::GET_GAME_TIMER();
	hashKey = MISC::GET_HASH_KEY(scriptName);

	if (SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(hashKey) == 0)
	{
		SCRIPT::REQUEST_SCRIPT(scriptName);
	
		while (!SCRIPT::HAS_SCRIPT_LOADED(scriptName))
		{
			SCRIPT::REQUEST_SCRIPT(scriptName);
			SYSTEM::WAIT(0);
		
			if (MISC::GET_GAME_TIMER() > gameTimer + 20000)
				SCRIPT::TERMINATE_THIS_THREAD();
		}
	
		if (SCRIPT::HAS_SCRIPT_LOADED(scriptName))
		{
			SYSTEM::START_NEW_SCRIPT(scriptName, DEFAULT);
			SCRIPT::SET_SCRIPT_AS_NO_LONGER_NEEDED(scriptName);
		}
	}

	SCRIPT::TERMINATE_THIS_THREAD();
	return;
}

Vector3 func_1(int iParam0) // Position - 0x1FF
{
	int num;

	num = iParam0;
	return Global_32543[num /*23*/][0 /*3*/];
}

BOOL func_2(Player plParam0) // Position - 0x217
{
	if (plParam0 != _INVALID_PLAYER_INDEX())
		return IS_BIT_SET(Global_2657589[plParam0 /*466*/].f_321.f_5, 4);

	return false;
}

Player _INVALID_PLAYER_INDEX() // Position - 0x23C
{
	return -1;
}

BOOL func_4(Player plParam0) // Position - 0x245
{
	if (plParam0 != _INVALID_PLAYER_INDEX())
		return IS_BIT_SET(Global_1853910[plParam0 /*862*/].f_267.f_428.f_2, 16);

	return false;
}

BOOL func_5(Player plParam0) // Position - 0x26E
{
	if (plParam0 != _INVALID_PLAYER_INDEX())
		return IS_BIT_SET(Global_1853910[plParam0 /*862*/].f_267.f_365, 29);

	return false;
}

BOOL func_6() // Position - 0x295
{
	return IS_BIT_SET(Global_1853910[PLAYER::PLAYER_ID() /*862*/].f_36.f_18, 0);
}

BOOL func_7(Player plParam0) // Position - 0x2AE
{
	return IS_BIT_SET(Global_1853910[plParam0 /*862*/].f_139, 6);
}

int func_8() // Position - 0x2C3
{
	int num;

	num = Global_2672505;

	if (IS_BIT_SET(Global_1890444[num /*129*/].f_14, 0) && Global_1890444[num /*129*/].f_23 == 2)
		return 1;

	return 0;
}

int func_9(Player plParam0, BOOL bParam1, BOOL bParam2) // Position - 0x2F6
{
	if (bParam1)
		if (func_10(plParam0))
			return 1;

	!bParam2;

	if (Global_1853910[plParam0 /*862*/] == -1)
		return 0;

	return 1;
}

BOOL func_10(Player plParam0) // Position - 0x328
{
	return func_11(plParam0);
}

BOOL func_11(Player plParam0) // Position - 0x336
{
	return IS_BIT_SET(Global_1853910[plParam0 /*862*/].f_11.f_1, 0);
}

BOOL func_12(Ped pedParam0) // Position - 0x34D
{
	if (!ENTITY::DOES_ENTITY_EXIST(pedParam0))
		return false;

	return !ENTITY::IS_ENTITY_DEAD(pedParam0, false);
}

