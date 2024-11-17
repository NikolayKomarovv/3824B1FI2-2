#include <stdio.h>
#include <string.h>
void bubblesort(float arr[], char arr2[5][3], char arr3[5][50], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((strcmp(arr2[i], "MB") == 0 && strcmp(arr2[j], "KB") == 0) ||(strcmp(arr2[i], "GB") == 0 && strcmp(arr2[j], "MB") == 0) || (strcmp(arr2[i], "GB") == 0 && strcmp(arr2[j], "KB") == 0) || (strcmp(arr2[i], arr2[j])==0) && (arr[i] > arr[j])) {
				float tmp = arr[i];
				char name[50];
				char typp[3];
				strcpy_s(typp, arr2[i]);
				arr[i] = arr[j];
				arr[j] = tmp;
				strcpy_s(arr2[i], arr2[j]);
				strcpy_s(arr2[j], typp);
				strcpy_s(name, arr3[i]); 
				strcpy_s(arr3[i], arr3[j]);
				strcpy_s(arr3[j], name);
			}
		}
	}
}
void out_array(char arr1[5][50], float arr2[5], char arr3[5][3], int N) {
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%s %.2f %s\n", arr1[i], arr2[i], arr3[i]);
	}
}
void selection(float arr[], char arr2[5][3], char arr3[5][50], int N) {
	for (int i = 0; i < N; i++) {
		float mn = arr[i];
		int tmp = i;
		char tmp_typp[3];
		char name[50];
		strcpy_s(tmp_typp, arr2[i]);
		for (int j = i + 1; j < N; j++) {
			if ((strcmp(arr2[j], "KB") == 0 && strcmp(tmp_typp, "MB") == 0) || (strcmp(arr2[j], "MB") == 0 && strcmp(tmp_typp, "GB") == 0) || (strcmp(arr2[j], "KB") == 0 && strcmp(tmp_typp, "GB") == 0) || (strcmp(arr2[j], tmp_typp) == 0) && (arr[j] < mn)) {
				mn = arr[j];
				tmp = j;
				strcpy_s(tmp_typp, arr2[j]);
			}
		}
		if (i != tmp) {
			float x = arr[i];
			arr[i] = arr[tmp];
			arr[tmp] = x;
			strcpy_s(arr2[tmp], arr2[i]);
			strcpy_s(arr2[i], tmp_typp);
			strcpy_s(name, arr3[i]);
			strcpy_s(arr3[i], arr3[tmp]);
			strcpy_s(arr3[tmp], name);
		}
	}
}
struct Fileinfo {
	char path[60];
	char files_names[5][50];
	char type_file_size[5][3];
	float file_size[5];
};
int main() {
	struct Fileinfo Reports = { "C:|Users|your_name|Documents|Work|Reports", {{"Report_Q1_2023.docx"}, {"Monthly_Progress_Report_March.pdf"}, {"Financial_Analysis_Overview.xlsx"}, {"Project_Proposal_final.docx"}, {"Team_Meeting_Minutes.txt"}}, { {"KB"}, {"KB"}, {"MB"}, {"KB"}, {"KB"}}, {256, 450, 1.2, 300, 50}};
	struct Fileinfo Pictures = { "C:|Users|your_name|Pictures|Vacation|Summer2023", {{"Beach_Photo_01.jpg"}, {"Sunset_at_Lake.png"}, {"Family_Group_Picture.jpeg"}, {"Hiking_Trip_Scenery.tiff"}, {"City_Tour_Snapshots.zip"}}, { {"MB"}, {"MB"}, {"MB"}, {"MB"}, {"MB"}}, {2.5, 3, 4.2, 5, 6} };
	struct Fileinfo Installers = { "C:|Users|your_name|Downloads|Software|Installers", {{"Zoom_Installer.exe"}, {"Adobe_Reader_Setup.exe"}, {"Python_3.10_Installer.exe"}, {"VLC_Media_Player_Setup.exe"}, {"Visual_Studio_Code_Installer.exe"}}, { {"MB"}, {"MB"}, {"MB"}, {"MB"}, {"MB"}}, {85, 65, 45, 85, 90} };
	struct Fileinfo Music = { "C:|Users|your_name|Music|Playlists|Favorites", {{"Favorite_Song_1.mp3"}, {"Chill_Vibes_Album.flac"}, {"Workout_Mix.m4a"}, {"Top_Hits_2023.wav"}, {"Classical_Masters.mp3"}}, { {"MB"}, {"MB"}, {"MB"}, {"MB"}, {"MB"}}, {12, 4.5, 30, 10, 35} };
	struct Fileinfo Movies = { "C:|Users|your_name|Videos|Movies|Action", {{"Action_Flick_1.mp4"}, {"Epic_Battle_Scene.mkv"}, {"Action_Heroes_Collection.avi"}, {"Thrilling_Adventure.mp4"}, {"Ultimate_Fight_Compendium.mov"}}, { {"GB"}, {"GB"}, {"GB"}, {"GB"}, {"GB"}}, {1.4, 2.3, 3.6, 1.9, 2.7} };
	int flag_for_path = 0, flag_for_sort = 0;
	printf("Choose type of sort you want: 1 - bubble, 2 - selection\n");
	scanf_s("%d", &flag_for_sort);
	printf("Choose path that you want sort: 1 - Reports, 2 - Pictures, 3 - Installers, 4 - Music, 5 - Movies\n");
	scanf_s("%d", &flag_for_path);
	switch (flag_for_sort) {
	case 1:
	{
		switch (flag_for_path) {
		case 1: { 
			bubblesort(Reports.file_size, Reports.type_file_size, Reports.files_names, 5);
			out_array(Reports.files_names, Reports.file_size, Reports.type_file_size, 5);
			break; 
		}
		case 2: { 
			bubblesort(Pictures.file_size, Pictures.type_file_size, Pictures.files_names, 5);
			out_array(Pictures.files_names, Pictures.file_size, Pictures.type_file_size, 5);
			break; 
		}
		case 3: {
			bubblesort(Installers.file_size, Installers.type_file_size, Installers.files_names, 5);
			out_array(Installers.files_names, Installers.file_size, Installers.type_file_size, 5);
			break;
		}
		case 4: {
			bubblesort(Music.file_size, Music.type_file_size, Music.files_names, 5);
			out_array(Music.files_names, Music.file_size, Music.type_file_size, 5);
			break;
		}
		case 5: {
			bubblesort(Movies.file_size, Movies.type_file_size, Movies.files_names, 5);
			out_array(Movies.files_names, Movies.file_size, Movies.type_file_size, 5);
			break;
		}
		default: { printf("Something get wrong"); break; }
		}
		break;
	}
	case 2:
	{
		switch (flag_for_path) {
		case 1: {
			selection(Reports.file_size, Reports.type_file_size, Reports.files_names, 5);
			out_array(Reports.files_names, Reports.file_size, Reports.type_file_size, 5);
			break;
		}
		case 2: {
			selection(Pictures.file_size, Pictures.type_file_size, Pictures.files_names, 5);
			out_array(Pictures.files_names, Pictures.file_size, Pictures.type_file_size, 5);
			break;
		}
		case 3: {
			selection(Installers.file_size, Installers.type_file_size, Installers.files_names, 5);
			out_array(Installers.files_names, Installers.file_size, Installers.type_file_size, 5);
			break;
		}
		case 4: {
			selection(Music.file_size, Music.type_file_size, Music.files_names, 5);
			out_array(Music.files_names, Music.file_size, Music.type_file_size, 5);
			break;
		}
		case 5: {
			selection(Movies.file_size, Movies.type_file_size, Movies.files_names, 5);
			out_array(Movies.files_names, Movies.file_size, Movies.type_file_size, 5);
			break;
		}
		default: { printf("Something get wrong"); break; }
		}
		break;
	}
	default: { printf("Something get wrong"); break; }
	}
	return 0;
}