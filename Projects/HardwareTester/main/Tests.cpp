
#include "Tests.h"
#include <cstring>

using Hal::Dwt;
using Hal::Hardware;
using Hal::TimeLimit;

using namespace std;

const char *testPhrase = "RTC holds the memory with low power";

const char *GetTestPhrase()
{
	return testPhrase;
}

void TestSdCard()
{
	Hardware *system = Hal::Hardware::Instance();
	if (system->GetSdCard().Mount())
	{
		printf("Opening file\n");
		FILE *f = fopen("/sdcard/hello.txt", "w");
		if (f == NULL)
		{
			printf("Failed to open file for writing\n");
			return;
		}
		fprintf(f, "Hello, how are you?\n");
		fclose(f);
		printf("File written\n");

		// Check if destination file exists before renaming
		struct stat st;
		if (stat("/sdcard/foo.txt", &st) == 0)
		{
			// Delete it if it exists
			unlink("/sdcard/foo.txt");
		}

		// Rename original file
		printf("Renaming file\n");
		if (rename("/sdcard/hello.txt", "/sdcard/foo.txt") != 0)
		{
			printf("Rename failed\n");
			return;
		}

		// Open renamed file for reading
		printf("Reading file\n");
		f = fopen("/sdcard/foo.txt", "r");
		if (f == nullptr)
		{
			printf("Failed to open file for reading\n");
			return;
		}
		char line[64];
		fgets(line, sizeof(line), f);
		fclose(f);
		// strip newline
		char *pos = strchr(line, '\n');
		if (pos)
			*pos = '\0';
		printf("Read from file: '%s'", line);
	}
	else
		printf("Error: SdCard not mounted.\n");
}

void TestSpiffs()
{
	if (Hardware::Instance()->GetSpiffs().IsMounted() == false)
	{
		if (Hardware::Instance()->GetSpiffs().Mount() == false)
		{
			printf("\n\nSPIFFS failed!\n\n");
			return;
		}
	}

	printf("\n\nOpening file\n");
	FILE *f = fopen("/spiffs/hello.txt", "w");
	if (f == NULL)
	{
		printf("Failed to open file for writing");
		return;
	}
	fprintf(f, "SPIFFS is Working!!! Hooray!!! :D\n");
	fclose(f);
	printf("File written\n");

	// Check if destination file exists before renaming
	struct stat st;
	if (stat("/spiffs/foo.txt", &st) == 0)
	{
		// Delete it if it exists
		unlink("/spiffs/foo.txt");
	}

	// Rename original file
	printf("Renaming file\n");
	if (rename("/spiffs/hello.txt", "/spiffs/foo.txt") != 0)
	{
		printf("Rename failed\n");
		return;
	}

	printf("Reading Test file\n");
	f = fopen("/spiffs/lala.txt", "r");
	if (f == NULL)
	{
		printf("Failed to open file for reading\n");
		return;
	}

	char line[64];
	fgets(line, sizeof(line), f);
	fclose(f);

	// Open renamed file for reading
	printf("Reading Stored Test file\n");
	f = fopen("/spiffs/lala.txt", "r");
	if (f == NULL)
	{
		printf("Failed to open file for reading\n");
		return;
	}

	fgets(line, sizeof(line), f);
	fclose(f);
	// strip newline
	char *pos = strchr(line, '\n');
	if (pos)
	{
		*pos = '\0';
	}

	printf("Read from file: '%s'\n\n", line);
}

void PutCpuToSleep()
{
	printf("\n\nI'm going to bed and I will be back in 5 seconds. BYE :)\n\n");

	Hardware::Instance()->DeepSleep(5 * 1000 * 1000);
}

void SoftwareResetTest()
{
	Hardware::Instance()->SoftwareReset();
}

void ToggleFlashLed()
{
	Hardware::Instance()->GetLeds().Toggle(Hal::Leds::LedIndex::FlashLed);
}

char ReadKey()
{
	char key = 0;
	while (key == 0)
	{
		scanf("%c", &key);
		vTaskDelay(5);
	}
	return key;
}

void ReadString(char *string, uint8_t size)
{
	uint8_t i = 0;
	char key = 0;
	while (true)
	{
		vTaskDelay(1);
		scanf("%c", &key);
		if (key == 10) // [Enter]
		{
			string[i] = '\0';
			break;
		}
		else if (key == 8) // [Backspace]
		{
			printf("%c %c", 8, 8); // clean the previous char
			i--;
			key = 0;
		}
		else if (key != 0)
		{
			string[i] = key;
			printf("%c", key);
			i++;
			key = 0;
			if (i == size - 1) // if the last key has reached the end of the buffer
			{
				string[i + 1] = '\0';
				break;
			}
		}
	}
	printf("\n");
}

void WifiMenu()
{
	char test = 0;

	while (1)
	{
		switch (test)
		{
		case 's':
		case 'S':
		{
			char mode = 0;
			printf("\n\nSet the Wifi mode:\n\n");
			printf("[1] - Client\n");
			printf("[2] - Hotspot\n");
			printf("[3] - Mesh Network\n");
			mode = ReadKey();
			if (mode == '1')
			{
				Hardware::Instance()->GetWifi().SetMode(Hal::WifiConfiguration::Client);
				printf("Configured as Wifi Client.\n");
			}
			else if (mode == '2')
			{
				Hardware::Instance()->GetWifi().SetMode(Hal::WifiConfiguration::HotSpot);
				printf("Configured as HotSpot.\n");
			}
			else if (mode == '3')
			{
				Hardware::Instance()->GetWifi().SetMode(Hal::WifiConfiguration::Mesh);
				printf("Configured as Mesh network (not supported yet).\n");
			}
			else
				printf("Invalid option.\n");
		}
		break;
		case 'i':
		case 'I':
		{
			char ssid[Hal::WifiSsidMaxLength] = {};
			uint8_t i = 0;
			test = 0;
			printf("Enter the SSID:\n");
			ReadString(ssid, Hal::WifiSsidMaxLength);
			printf("\nSSID set to \"%s\"\n", ssid);
			scanf("%s", ssid);
			Hardware::Instance()->GetWifi().SetSsid(ssid, strlen(ssid));
		}
		break;
		case 'p':
		case 'P':
		{
			char passwd[Hal::WifiPasswordMaxLength] = {};
			printf("Enter the Password:\n");
			ReadString(passwd, Hal::WifiPasswordMaxLength);
			printf("\nPassword set to \"%s\"\n", passwd);
			Hardware::Instance()->GetWifi().SetPassword(passwd, strlen(passwd));
		}
		break;
		case 'c':
		case 'C':
		{
			char channel = 0;
			printf("Enter the channel: \n");
			channel = ReadKey();
			channel -= 48;
			printf("%d", channel);
			Hardware::Instance()->GetWifi().SetChannel(channel);
		}
		break;
		case 't':
		case 'T':
		{
			Hardware::Instance()->GetWifi().Enable();
		}
		break;
		case 'z':
		case 'Z':
		{
			Hardware::Instance()->GetWifi().Disable();
		}
		break;
		case 'x':
		case 'X':
		{
			return;
		}
		break;
		default:
			break;
		}

		printf("\n");
		printf("Wifi menu:\n");
		printf("----------\n");
		printf("[S] - Set WiFi Mode (AP, STA or Mesh)\n");
		printf("[I] - Set WiFi SSID\n");
		printf("[P] - Set WiFi Password\n");
		printf("[C] - Set WiFi Channel\n");
		printf("[T] - Start Wifi\n");
		printf("[Z] - Stop Wifi\n");
		printf("[X] - Return\n");

		test = ReadKey();
	}
}