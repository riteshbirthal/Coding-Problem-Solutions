class Solution {
    vector<int> hour, minute;
public:
    void possibleMinutes(int minuteLEDs, int minutes, int idx, vector<string>& vec){
        if(minuteLEDs==0 || idx==minute.size()){
            if(minutes<60 && minuteLEDs==0)
                vec.push_back(minutes<10 ? "0" + to_string(minutes) : to_string(minutes));
            return ;
        }
        possibleMinutes(minuteLEDs, minutes, idx+1, vec);
        possibleMinutes(minuteLEDs-1, minutes + minute[idx], idx+1, vec);
        return ;
    }

    void possibleHours(int hourLEDs, int hours, int idx, vector<string>& vec){
        if(hourLEDs==0 || idx==hour.size()){
            if(hours<12 && hourLEDs==0)
                vec.push_back(to_string(hours));
            return ;
        }
        possibleHours(hourLEDs, hours, idx+1, vec);
        possibleHours(hourLEDs-1, hours + hour[idx], idx+1, vec);
        return ;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        hour = {1, 2, 4, 8};
        minute = {1, 2, 4, 8, 16, 32};
        for(int i = 0; i <= turnedOn; i++){
            vector<string> hours, minutes;
            possibleHours(i, 0, 0, hours);
            possibleMinutes(turnedOn-i, 0, 0, minutes);
            if(hours.size()==0 || minutes.size()==0)
                continue;
            int h = hours.size(), m = minutes.size();
            for(int j = 0; j < h; j++){
                for(int k = 0; k < m; k++){
                    res.push_back(hours[j] + ":" + minutes[k]);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
