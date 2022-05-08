#ifndef USERCOMMANDCPP
#define USERCOMMANDCPP

UserCommand::UserCommand(CommandType cType) {
	type = cType;
	nodeIndices[0] = NULL;
	nodeIndices[1] = NULL;
}
UserCommand::UserCommand(CommandType cType, int indices[]) {
	type = cType;
	nodeIndices[0] = indices[0];
	nodeIndices[1] = indices[1];
}
CommandType UserCommand::getType() {
	return type;
}
int* UserCommand::getIndices() {
	return nodeIndices;
}

#endif