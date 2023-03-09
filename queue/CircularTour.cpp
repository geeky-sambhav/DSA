
deficit mein kami ko store krlo
aur fir agle se shuru kro
agr last mein jo remaining balance deficit ko pura kr rha to start ko return krdo

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int deficit=0;
        int start=0;
        int balance=0;
        for (int i=0;i<n;i++){
            balance+=p[i].petrol-p[i].distance;
            if(balance<0){
                start=i+1;
                
                deficit+=balance;
                balance=0;
            }
            
        }
        
        if(balance+deficit>0){
            return start;
        }
        else{
            return -1;
        }
    }
};
