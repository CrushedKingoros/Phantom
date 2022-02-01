//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Minecraft.h"
#include "WorldClient.h"

WorldClient::WorldClient(Phantom *phantom, Minecraft *mc) : AbstractClass::AbstractClass(phantom, "WorldClient") {
	this->mc = mc;
	fdEntityList = getFieldID("entities");
	mdSetWorldTime = getMethodID("setTime");
}

jobject WorldClient::getEntityList() {
    if (mc->getWorld() == nullptr)
        return nullptr;

	return getObject(mc->getWorld(), fdEntityList);
}

void WorldClient::setWorldTime(jlong time) {
	callMethod(mc->getWorld(), mdSetWorldTime, time);
}

JavaSet *WorldClient::getEntities() {
	auto *set = new JavaSet(phantom, getEntityList());
	return set;
}
