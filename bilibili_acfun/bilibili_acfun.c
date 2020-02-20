#include <stdio.h>

int main(void)
{
    unsigned int i,x,y,t,s,speed_difference;//测试次数/播放速度/下载速度/等待时间/视频大小/速度差
    double watch_time ,download_process_bar,interval_time = 0;//观看时间/进度条/每次观看时间
    scanf("%d",&i);
    for(unsigned int n = 0;n < i;n ++)
    {
        watch_time = 0;
        scanf("%d%d%d%d",&x,&y,&t,&s);
        printf("Case #%d:",n+1);
        if((t + (double)s) / x > (double)s / y)//不用拖进度条
        {
            watch_time = (double)s / x;
            printf(" %.3lf\n",watch_time);
        }
        else//要拖进度条
        {
            speed_difference = x - y;
            download_process_bar = (double)t * y / s;
            while (download_process_bar < 1)
            {
                interval_time = download_process_bar * s / speed_difference;
                if((interval_time + watch_time + t) * y <= s)//还未加载完就追上
                    watch_time += interval_time;
                else//最后一次追上前加载完
                    watch_time += (double)s/x;
                 download_process_bar = (t + watch_time) * y / s;               
            }
            printf(" %.3lf\n",watch_time);
        }
    }
    return 0;
}
