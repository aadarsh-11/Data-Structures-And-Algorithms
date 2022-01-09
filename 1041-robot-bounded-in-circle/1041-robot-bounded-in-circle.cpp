class Solution {
public:
    
    bool check_origin(int h,int v){
        if(h == 0 && v == 0)
			return true;
		return false;
    }
	
    bool isRobotBounded(string instructions) {
        
        char curr_dir = 'N';
    
        //unordered_map<char,int> map;
        int vertical = 0, horizontal= 0;
        for(int i=0;i<instructions.length();i++){ 
            if(instructions[i] == 'G'){
                vertical += curr_dir =='N' ? 1 : 0;
				vertical += curr_dir =='S' ? -1 : 0;
				horizontal += curr_dir == 'E' ? 1 : 0;
				horizontal += curr_dir == 'W' ? -1 : 0;
            }
            else{
                char incoming = instructions[i];
                if(curr_dir == 'N'){
                    curr_dir = incoming == 'L' ? 'W' : 'E';
                }
                else if(curr_dir == 'W'){
                    curr_dir = incoming == 'L' ? 'S' : 'N';
                }
                else if(curr_dir == 'S'){
                    curr_dir = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    curr_dir = incoming == 'L' ? 'N' : 'S';
                }
            } 
            
        }
        if(check_origin(horizontal,vertical) || curr_dir!='N')
            return true;
        
        return false;
    }
};