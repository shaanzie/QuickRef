package Code Examples.X10;

public class pi_parallel {

    public class AsyncPi {

        public static def main(s: Array[String](!)):Void {
            
        val samplesPerActivity = 10000;
        val numActivities = 8;
        val activityCounts = new Array[Double](1..numActivities, (Point)=>0.0);
        finish for (activityID in 1..numActivities) {
        async {
        val [ActivityIndex] = activityID;
        val r = new Random(activityIndex);
        for (i in 1..samplesPerActivity) {
        val x = r.nextDouble();
        val y = r.nextDouble();
        val z = x*x+y*y;
        if ((x*x + y*y) <= 1.0) {
        activityCounts(activityID)++;
        }
        }
        }
        }
        var globalCount:Double = 0.0;
        for (activityID in 1..numActivities) {
        globalCount += activityCounts(activityID);
        }
        val pi = 4*(globalCount/(samplesPerActivity*numActivities as Double));
        Console.OUT.println("With " +<snip>+" points, the value of pi is " + pi);
        }
       }

}