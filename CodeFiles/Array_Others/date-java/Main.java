/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;
import java.util.Date;
import java.sql.Timestamp;

public class Main
{
    
    /*
    private int GetRandomNumber(int min,int max)
    {
        Random random_number = new Random();
        return min + random_number.nextInt(max);
    }
    
    private String GenerateRandomTime()
    {
        int min_hour = Integer.parseInt(0);
        int max_hour = Integer.parseInt(31);
        int hour_part = GetRandomNumber(min_hour,max_hour);
        hour_part = (int)((hour_part * 15) / 60);
        hour_part = (Constants.mail_hour_Check_Offset + hour_part) % 24;
        int minute_part = GetRandomNumber(0,59) % 60;
        int second_part = GetRandomNumber(0,59) % 60;

        Calendar instance = Calendar.getInstance();
        instance.set(Calendar.HOUR_OF_DAY,hour_part);
        instance.set(Calendar.MINUTE,minute_part);
        instance.set(Calendar.SECOND,second_part);
        return instance.toString();
    }
    */
    
    /*
	public static void main(String[] args) throws Exception {
// 		System.out.println("Hello World");
// 		 Calendar instance = Calendar.getInstance();
// 		System.out.println(instance.toString());
		
		Date date = Calendar.getInstance().getTime();  
        DateFormat dateFormat = new SimpleDateFormat("yyyy-mm-dd hh:mm:ss");  
        String strDate = dateFormat.format(date); 
        System.out.println(strDate);
        
        Date date1=dateFormat.parse(strDate);  
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date1);
        System.out.println(calendar.get(Calendar.DATE));  
        System.out.println(calendar.get(Calendar.YEAR));  
        System.out.println(calendar.get(Calendar.MONTH));  
        System.out.println(calendar.get(Calendar.HOUR_OF_DAY));  
        System.out.println(calendar.get(Calendar.MINUTE));  
        System.out.println(calendar.get(Calendar.SECOND));  
        // System.out.println(calendar.getTime(Calendar.SECOND));
        
	}
	*/
	
    public static void main(String a[])
    {
     
    // String startDate = "24/02/2014 12:30:00";
    // String endDate = "22/02/2014 12:30:00";
    
    String startDate = "12:30:00";
    String endDate = "12:30:00"; 
    
    /**
     * SimpleDateFormat converts string format to date object
     */
    SimpleDateFormat sdFormat = new SimpleDateFormat("HH:mm:ss");
    try {
        Date startDateObj = sdFormat.parse(startDate);
        Date endDateObj = sdFormat.parse(endDate);
        // startDateObj.getTime() method gives date in milli seconds format
        System.out.println("Time in milli seconds: "+startDateObj.getTime());
         
        // find time difference in milli seconds
        long timeDiff = endDateObj.getTime() - startDateObj.getTime();
        System.out.println("Time difference in Milli seconds: "+timeDiff);
         
        // time difference in seconds
        long secondsDiff = (timeDiff/1000);
        System.out.println("Time difference in seconds: "+secondsDiff);
         
        // time difference in minutes
        long minDiff = timeDiff/(1000*60);
        System.out.println("Time difference in minutes: "+minDiff);
         
        // time difference in minutes
        long hoursDiff = timeDiff/(1000*60*60);
        System.out.println("Time difference in hours: "+hoursDiff);
         
        // time difference in minutes
        long daysDiff = timeDiff/(1000*60*60*24);
        System.out.println("Time difference in days: "+daysDiff);
         
    } catch (Exception e) {
        // TODO Auto-generated catch block
        e.printStackTrace();
    }
}
}
