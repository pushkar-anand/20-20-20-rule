#include <libnotify/notify.h>
#include <iostream>

using namespace std;

int sendNotification();
void startBeeps();

int main()
{
  int c;
  c = sendNotification();
  return 0;
}

int sendNotification()
{
    notify_init("Reminding User");
    NotifyNotification* n = notify_notification_new ("Hii Pushkar!",
                                 "Please look away from your screen untill the beeping stops",
                                  "user-available");
    notify_notification_set_timeout(n, 20000); // 20 seconds

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
	system("canberra-gtk-play -f sound.wav");
}