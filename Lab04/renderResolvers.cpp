#include "renderResolvers.hpp"
#include <iomanip>

using namespace std;

//1 = 100000km

void handleRealTimeTransformations() {
	const GLfloat time = (GLfloat)glfwGetTime() * 10;
}

void processObjects() {
	objectsToRender.clear();

	ObjectsToRender floor;
	floor.index = INDEX_CUBE;
	floor.translation = vec3(0.0f, 0.0f, 0.0f);
	floor.scaling = vec3(100.0f, 0.8f, 100.0f);
	floor.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
	floor.index_texture = GRASS_INDEX;

	objectsToRender.push_back(floor);

	if (states.exercise == 1) {
		for (int i = 0; i < 12; i++) {
			ObjectsToRender cube;
			cube.index = INDEX_CUBE;
			cube.translation = vec3(i * 15 + -80.0f, 7.0f, 0.0f);
			cube.scaling = vec3(5.0f, 5.0f, 5.0f);
			cube.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
			cube.index_texture = BRICK_INDEX;

			objectsToRender.push_back(cube);
		}
	}
	else if (states.exercise == 2) {
		ObjectsToRender cube;
		cube.index = INDEX_CUBE;
		cube.translation = vec3(0.0f, 6.0f, 0.0f);
		cube.scaling = vec3(5.0f, 5.0f, 5.0f);
		cube.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		cube.index_texture = ROOF_INDEX;

		objectsToRender.push_back(cube);

		cube.translation = vec3(30.0f, 6.0f, 0.0f);
		objectsToRender.push_back(cube);
	}

	else if (states.exercise == 4) {
		ObjectsToRender house_on_pieces_front;
		house_on_pieces_front.index = INDEX_CUBE;
		house_on_pieces_front.translation = vec3(70.0f, 31.0f, 30.0f);
		house_on_pieces_front.scaling = vec3(30.0f, 30.0f, 3.0f);
		house_on_pieces_front.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_front.index_texture = BRICK_INDEX;

		ObjectsToRender house_on_pieces_top;
		house_on_pieces_top.index = INDEX_CUBE;
		house_on_pieces_top.translation = vec3(70.0f, 58.0f, 0.0f);
		house_on_pieces_top.scaling = vec3(27.0f, 3.0f, 27.0f);
		house_on_pieces_top.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_top.index_texture = BRICK_INDEX;

		ObjectsToRender house_on_pieces_back;
		house_on_pieces_back.index = INDEX_CUBE;
		house_on_pieces_back.translation = vec3(70.0f, 31.0f, -30.0f);
		house_on_pieces_back.scaling = vec3(30.0f, 30.0f, 3.0f);
		house_on_pieces_back.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_back.index_texture = BRICK_INDEX;

		ObjectsToRender house_on_pieces_bottom;
		house_on_pieces_bottom.index = INDEX_CUBE;
		house_on_pieces_bottom.translation = vec3(70.0f, 4.0f, 0.0f);
		house_on_pieces_bottom.scaling = vec3(27.0f, 3.0f, 27.0f);
		house_on_pieces_bottom.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_bottom.index_texture = BRICK_INDEX;

		ObjectsToRender house_on_pieces_left;
		house_on_pieces_left.index = INDEX_CUBE;
		house_on_pieces_left.translation = vec3(43.0f, 31.0f, 0.0f);
		house_on_pieces_left.scaling = vec3(3.0f, 30.0f, 27.0f);
		house_on_pieces_left.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_left.index_texture = BRICK_INDEX;

		ObjectsToRender house_on_pieces_right;
		house_on_pieces_right.index = INDEX_CUBE;
		house_on_pieces_right.translation = vec3(97.0f, 31.0f, 0.0f);
		house_on_pieces_right.scaling = vec3(3.0f, 30.0f, 27.0f);
		house_on_pieces_right.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_on_pieces_right.index_texture = BRICK_INDEX;

		ObjectsToRender roof;
		roof.index = INDEX_TRIANGLE;
		roof.translation = vec3(70.0f, 91.0f, 0.0f);
		roof.scaling = vec3(30.0f, 30.0f, 30.0f);
		roof.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof.index_texture = ROOF_INDEX;

		ObjectsToRender door;
		door.index = INDEX_CUBE;
		door.translation = vec3(40.0f, 11.0f, 0.0f);
		door.scaling = vec3(1.0f, 10.0f, 5.0f);
		door.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door.index_texture = DOOR_ONE_INDEX;

		ObjectsToRender building1;
		building1.index = INDEX_CUBE;
		building1.translation = vec3(-70.0f, 31.0f, 0.0f);
		building1.scaling = vec3(30.0f, 30.0f, 30.0f);
		building1.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		building1.index_texture = BRICK_INDEX;

		ObjectsToRender building2;
		building2.index = INDEX_CUBE;
		building2.translation = vec3(-70.0f, 61.0f, 0.0f);
		building2.scaling = vec3(30.0f, 30.0f, 30.0f);
		building2.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		building2.index_texture = BRICK_INDEX;

		ObjectsToRender building3;
		building3.index = INDEX_CUBE;
		building3.translation = vec3(-70.0f, 91.0f, 0.0f);
		building3.scaling = vec3(30.0f, 30.0f, 30.0f);
		building3.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		building3.index_texture = BRICK_INDEX;

		ObjectsToRender building4;
		building4.index = INDEX_CUBE;
		building4.translation = vec3(-70.0f, 121.0f, 0.0f);
		building4.scaling = vec3(30.0f, 30.0f, 30.0f);
		building4.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		building4.index_texture = BRICK_INDEX;

		ObjectsToRender door_building;
		door_building.index = INDEX_CUBE;
		door_building.translation = vec3(-40.0f, 11.0f, 0.0f);
		door_building.scaling = vec3(1.0f, 10.0f, 5.0f);
		door_building.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_building.index_texture = DOOR_TWO_INDEX;

		ObjectsToRender asphalt;
		asphalt.index = INDEX_CUBE;
		asphalt.translation = vec3(0.0f, 1.1f, 30.0f);
		asphalt.scaling = vec3(10.0f, 0.1f, 70.0f);
		asphalt.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		asphalt.index_texture = ASPHALT_INDEX;

		ObjectsToRender house_01;
		house_01.index = INDEX_CUBE;
		house_01.translation = vec3(-85.0f, 11.0f, -85.0f);
		house_01.scaling = vec3(10.0f, 10.0f, 10.0f);
		house_01.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_01.index_texture = BRICK_INDEX;

		ObjectsToRender roof_house_01;
		roof_house_01.index = INDEX_TRIANGLE;
		roof_house_01.translation = vec3(-85.0f, 31.0f, -85.0f);
		roof_house_01.scaling = vec3(10.0f, 10.0f, 10.0f);
		roof_house_01.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof_house_01.index_texture = ROOF_INDEX;

		ObjectsToRender door_house_01;
		door_house_01.index = INDEX_CUBE;
		door_house_01.translation = vec3(-85.0f, 6.0f, -75.0f);
		door_house_01.scaling = vec3(2.5f, 5.0f, 1.0f);
		door_house_01.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_house_01.index_texture = DOOR_THREE_INDEX;

		ObjectsToRender house_02;
		house_02.index = INDEX_CUBE;
		house_02.translation = vec3(-45.0f, 16.0f, -80.0f);
		house_02.scaling = vec3(15.0f, 15.0f, 15.0f);
		house_02.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_02.index_texture = BRICK_INDEX;

		ObjectsToRender roof_house_02;
		roof_house_02.index = INDEX_TRIANGLE;
		roof_house_02.translation = vec3(-45.0f, 46.0f, -80.0f);
		roof_house_02.scaling = vec3(15.0f, 15.0f, 15.0f);
		roof_house_02.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof_house_02.index_texture = ROOF_INDEX;

		ObjectsToRender door_house_02;
		door_house_02.index = INDEX_CUBE;
		door_house_02.translation = vec3(-45.0f, 8.5f, -65.0f);
		door_house_02.scaling = vec3(3.75f, 7.5f, 1.0f);
		door_house_02.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_house_02.index_texture = DOOR_FOUR_INDEX;

		ObjectsToRender house_03;
		house_03.index = INDEX_CUBE;
		house_03.translation = vec3(0.0f, 21.0f, -75.0f);
		house_03.scaling = vec3(20.0f, 20.0f, 20.0f);
		house_03.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_03.index_texture = BRICK_INDEX;

		ObjectsToRender roof_house_03;
		roof_house_03.index = INDEX_TRIANGLE;
		roof_house_03.translation = vec3(0.0f, 61.0f, -75.0f);
		roof_house_03.scaling = vec3(20.0f, 20.0f, 20.0f);
		roof_house_03.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof_house_03.index_texture = ROOF_INDEX;

		ObjectsToRender door_house_03;
		door_house_03.index = INDEX_CUBE;
		door_house_03.translation = vec3(0.0f, 11.0f, -55.0f);
		door_house_03.scaling = vec3(5.0f, 10.0f, 1.0f);
		door_house_03.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_house_03.index_texture = DOOR_FIVE_INDEX;

		ObjectsToRender house_04;
		house_04.index = INDEX_CUBE;
		house_04.translation = vec3(45.0f, 18.0f, -78.0f);
		house_04.scaling = vec3(17.0f, 17.0f, 17.0f);
		house_04.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_04.index_texture = BRICK_INDEX;

		ObjectsToRender roof_house_04;
		roof_house_04.index = INDEX_TRIANGLE;
		roof_house_04.translation = vec3(45.0f, 52.0f, -78.0f);
		roof_house_04.scaling = vec3(17.0f, 17.0f, 17.0f);
		roof_house_04.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof_house_04.index_texture = ROOF_INDEX;

		ObjectsToRender door_house_04;
		door_house_04.index = INDEX_CUBE;
		door_house_04.translation = vec3(45.0f, 9.5f, -61.0f);
		door_house_04.scaling = vec3(4.25f, 8.5f, 1.0f);
		door_house_04.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_house_04.index_texture = DOOR_SIX_INDEX;

		ObjectsToRender house_05;
		house_05.index = INDEX_CUBE;
		house_05.translation = vec3(85.0f, 13.0f, -83.0f);
		house_05.scaling = vec3(12.0f, 12.0f, 12.0f);
		house_05.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		house_05.index_texture = BRICK_INDEX;

		ObjectsToRender roof_house_05;
		roof_house_05.index = INDEX_TRIANGLE;
		roof_house_05.translation = vec3(85.0f, 37.0f, -83.0f);
		roof_house_05.scaling = vec3(12.0f, 12.0f, 12.0f);
		roof_house_05.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		roof_house_05.index_texture = ROOF_INDEX;

		ObjectsToRender door_house_05;
		door_house_05.index = INDEX_CUBE;
		door_house_05.translation = vec3(85.0f, 7.0f, -71.0f);
		door_house_05.scaling = vec3(3.0f, 6.0f, 1.0f);
		door_house_05.rotation = { vec3(0.0f, 1.0f, 0.0f), 0.0f };
		door_house_05.index_texture = DOOR_SEVEN_INDEX;

		objectsToRender.push_back(house_on_pieces_front);
		objectsToRender.push_back(house_on_pieces_top);
		objectsToRender.push_back(house_on_pieces_back);
		objectsToRender.push_back(house_on_pieces_bottom);
		objectsToRender.push_back(house_on_pieces_left);
		objectsToRender.push_back(house_on_pieces_right);
		objectsToRender.push_back(roof);
		objectsToRender.push_back(door);

		objectsToRender.push_back(building1);
		objectsToRender.push_back(building2);
		objectsToRender.push_back(building3);
		objectsToRender.push_back(building4);
		objectsToRender.push_back(door_building);

		objectsToRender.push_back(asphalt);

		objectsToRender.push_back(house_01);
		objectsToRender.push_back(roof_house_01);
		objectsToRender.push_back(door_house_01);

		objectsToRender.push_back(house_02);
		objectsToRender.push_back(roof_house_02);
		objectsToRender.push_back(door_house_02);

		objectsToRender.push_back(house_03);
		objectsToRender.push_back(roof_house_03);
		objectsToRender.push_back(door_house_03);

		objectsToRender.push_back(house_04);
		objectsToRender.push_back(roof_house_04);
		objectsToRender.push_back(door_house_04);

		objectsToRender.push_back(house_05);
		objectsToRender.push_back(roof_house_05);
		objectsToRender.push_back(door_house_05);
	}

}

