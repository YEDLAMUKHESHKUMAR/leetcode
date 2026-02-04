class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n == 0){
            vector<int> ans(numCourses);
            for(int i = 0; i < numCourses; i++) ans[i] = i;
            return ans;
        }
        int coursesCompleted = 0;
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n ;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        queue<int> courses;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) {
                courses.push(i);
            }
        }
        while(!courses.empty()){
            int currCourse = courses.front();
            courses.pop();
            coursesCompleted++;
            ans.push_back(currCourse);
            for(auto adj : graph[currCourse]){
                indegree[adj]--;
                if(indegree[adj] == 0) courses.push(adj);
            }
        }
        cout<<coursesCompleted;
        if(coursesCompleted != numCourses) return {};

        return ans;

    }
};