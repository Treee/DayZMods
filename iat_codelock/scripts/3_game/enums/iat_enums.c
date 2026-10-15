enum IAT_MenuType
{
	CODELOCK_MANAGER = 1, // custom menu for managing codelocks
	PASSCODE_ENTRY = 2, // for entering passcodes
}

enum IAT_RPC_Codelock
{
	UPDATE_OWNER = -867542, // first time codelock set, sends to all players on server
	UPDATE_OWNER_CLIENT = -867543, // first time player interact AND owner id is empty
	UPDATE_LOCK_STATE_CLIENT = -867544, // client side rpc to toggle the lock state
	UPDATE_PASSCODE_CLIENT = -867545, // client side rpc to change the passcode
	UPDATE_WHITELIST = -867546, // server side rpc to update the current players whitelist
	ENTER_PASSCODE_CLIENT = -867547, // client side rpc to enter the passcode
	FAILED_PASSCODE_ENTRY = -867548, // server side rpc to handle failed passcode entry
	CLEAR_WHITELIST = -867549, // server side rpc to clear the whitelist
	CHECK_CODELOCK_CONFIG = -867550, // server side rpc to sync the codelock config to client
}
