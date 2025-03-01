#include "Commands.h"
#include <iostream>

#include "SceneGraph/GameObject.h"

SB::MoveCommand::MoveCommand(Engine::GameObject* pObject)
	: Engine::Command(pObject)
{
}

void SB::MoveCommand::Execute()
{
	std::cout << "MoveCommand executed on " << m_pObject->GetName() << '\n';
}
