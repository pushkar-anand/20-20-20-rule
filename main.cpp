#include <libnotify/notify.h>
#include <iostream>
#include <string>
#include <experimental/filesystem>

using namespace std;

int sendNotification();
void startBeeps();

int main()
{
  sleep(1200); //sleep for 20 minutes
  int c;
  c = sendNotification();
  main(); // re-run the main
  return 0;
}

int sendNotification()
{
    notify_init("Reminding User");
    NotifyNotification* n = notify_notification_new ("Hii Pushkar!",
                                 "Please look away from your screen untill the music stops",
                                  "user-available");
    notify_notification_set_timeout(n, 20000); 

    if (!notify_notification_show(n, 0))
    {
        std::cerr << "show has failed" << std::endl;
        return -1;
    }
    startBeeps();
    return 1;
}

void startBeeps()
{
	string path = experimental::filesystem::current_path();
	string fullPath = path + "/sound.wav";
	string cmd = "canberra-gtk-play -f " + fullPath;
	system(cmd.c_str());
}
