#include "textures.hpp"

string tex = "Textures/";
string png = ".png";
vector<string> files {
	"empty",
	"wall",
	"roof",
	"asphalt",
	"grass",
	"door_1",
	"door_2",
	"door_3",
	"door_4",
	"door_5",
	"door_6",
	"door_7",
};

vector<Texture> textures;

void loadTextures() {
	unsigned char* TEXTURE = NULL;
	GLint TEXTURE_WIDTH = 0;
	GLint TEXTURE_HEIGHT = 0;

	for (GLint i = 0; i < files.size(); i++) {
		TEXTURE = NULL;
		TEXTURE_WIDTH = 0;
		TEXTURE_HEIGHT = 0;
		string texture_name = tex + files[i] + png;

		TEXTURE = SOIL_load_image(texture_name.data(), &TEXTURE_WIDTH, &TEXTURE_HEIGHT, NULL, SOIL_LOAD_RGBA);

		if (!TEXTURE) {
			cout << "ERROR LOADING TEXTURE " << i << endl;
			exit(0);
		}

		textures.push_back({ TEXTURE_WIDTH, TEXTURE_HEIGHT, TEXTURE });
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void applyTexture(unsigned char* TEXTURE, GLint TEXTURE_WIDTH, GLint TEXTURE_HEIGHT) {
	if (TEXTURE) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, TEXTURE);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void freeTextures() {
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);

	for (GLint i = 0; i < textures.size(); i++) {
		SOIL_free_image_data(textures[i].TEXTURE);
	}
}