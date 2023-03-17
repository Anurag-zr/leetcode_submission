class Solution {
    public boolean canCross(int[] stones) {
        
        HashMap<Integer,HashSet<Integer>> map = new HashMap<Integer,HashSet<Integer>>();
        
        for(int stone : stones){
            map.put(stone,new HashSet<Integer>());
        }
        map.get(0).add(1); 
        
        for(int i=0;i<stones.length;i++){
            int stone = stones[i];
            
            for(int step : map.get(stone)){
                int reach = stone + step;
                
                if(reach==stones[stones.length-1]) return true;
                
                if(map.get(reach)!=null){
                    HashSet<Integer> set = map.get(reach);
                    set.add(step);
                    if(step-1>0) set.add(step-1);
                    set.add(step+1);
                }
            }
        }
        
        return  false;
    }
}