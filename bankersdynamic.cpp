#include <bits/stdc++.h>

using namespace std;

#define MAX_CHAR 100



struct process
{
    int pid,pavt;



        bool operator< (const process & p)const
        {
            
            if(pavt==p.pavt)
            {
                return pid>p.pid;
            }
            else
            {
                return pavt>p.pavt;
            }
            
        }
};

vector<int> remove_space(string str)
{


    // string s = "4 1 0 3 2 140";

    string s = str;
    vector<int> result;

    istringstream iss(s);
    for(int s; iss >> s;)
        result.push_back(s);

    // int total=0;

    // cout<<"remove_space"<<endl;
    // for(auto& s: result)
    // {
    //             cout << s << ' ';
    //             total+=s;
    // }
    // cout<<total<<endl;

    return result;
}



int main(int argc,char* argv[]) 
{
    char str[MAX_CHAR];

    //char filename[MAX_CHAR];

   // scanf("%s",&filename);

   if(argv[1]==NULL && argv[2]==NULL)
    {
        printf("file name is empty\n");
        return 0;
    }
    printf("%s\n",argv[1]);

    FILE *fp;
    fp=fopen(argv[1], "r");

     FILE *fptr;
    fptr=fopen(argv[2], "w");


    int i=1,j=0,li;
    int num_proc,num_res,num_query;
    
    vector<int> process_id;
    vector<int> arrival_time;
    vector<int> avail_res;

    vector<int> temp;

    vector< vector<int> > max_res;
    vector< vector<int> > res_alloc;
    vector< vector<int> > query;

    //int max_res[5][3];
    //int res_alloc[5][3];
   // int query[5][4];

    int k;
    int start_ra;
    int start_qu;

    vector<int> temp_array;

    while(fgets(str, MAX_CHAR, fp)!=NULL) 
    {  
        
       

        if(i==1)
        {
            num_proc=str[0]-'0';
            num_res=str[2]-'0';
            num_query=str[4]-'0';

            //printf("%d\n",strlen(str) );
            //printf("%d %d %d\n",num_proc,num_res,num_query);

            start_ra=5+num_proc;
            start_qu=start_ra+num_proc;


        }
        else if(i==2)
        {


            temp_array = remove_space(str);
            process_id=temp_array;
        
          
             // for(int x=0;x<process_id.size();x++)
             // {
             //    printf("%d ",process_id.at(x));
             // } 
            
             temp_array.clear();
            
            printf("\n");
            
        }
        else if(i==3)
        {

            
            temp_array = remove_space(str);
            //arrival_time.assign(temp_array.begin(), temp_array.end());
            arrival_time=temp_array;
        
          
             // for(int x=0;x<arrival_time.size();x++)
             // {
             //    printf("%d ",arrival_time.at(x));
             // } 
             printf("\n"); 

             
             temp_array.clear();


                
            
        }
        else if(i==4)
        {

           //  printf("4 inside\n");
            
             temp_array = remove_space(str);
             avail_res=temp_array;
             temp_array.clear();    
             
             // for(int x=0;x<avail_res.size();x++)
             // {
             //    printf("%d ",avail_res.at(x));
             // }

              printf("\n"); 

             
             //break;
            
            
            
        }
        else if(i>=5&&i<5+num_proc)
        {


            temp_array = remove_space(str);
            max_res.push_back(temp_array);
           
            
            // for(int x=0;x<temp_array.size();x++)
            // {
            //     printf("%d ",temp_array.at(x));
            // }

            // printf("\n");
            temp_array.clear(); 

            // if(max_res.size()==num_proc)
            // {
            //     for(int ix=0;ix<max_res.size();ix++)
            //     {
            //         for(int jx=0;jx<max_res[ix].size();jx++)
            //         {
            //             printf("%d ",max_res[ix][jx]);
            //         }
            //         printf("\n");
            //     }

            // }

             
               
            
        }
        else if(i>=start_ra&&i<start_ra+num_proc)
        {

            



            temp_array = remove_space(str);
            res_alloc.push_back(temp_array);
           
            
            // for(int x=0;x<temp_array.size();x++)
            // {
            //     printf("%d ",temp_array.at(x));
            // }

            // printf("\n");
            temp_array.clear(); 


            // if(res_alloc.size()==num_proc)
            // {
            //     for(int ix=0;ix<res_alloc.size();ix++)
            //     {
            //         for(int jx=0;jx<res_alloc[ix].size();jx++)
            //         {
            //             printf("%d ",res_alloc[ix][jx]);
            //         }
            //         printf("\n");
            //     }

            // }

    

        }   
        else if(i>=start_qu&&i<start_qu+num_query)
        {
            


            temp_array = remove_space(str);
            query.push_back(temp_array);
           
            
            // for(int x=0;x<temp_array.size();x++)
            // {
            //     printf("%d ",temp_array.at(x));
            // }

            // printf("\n");

            // if(query.size()==num_query)
            // {
            //     for(int ix=0;ix<query.size();ix++)
            //     {
            //         for(int jx=0;jx<query[ix].size();jx++)
            //         {
            //             printf("%d ",query[ix][jx]);
            //         }
            //         printf("\n");
            //     }

            // }
            temp_array.clear(); 


        }

            i++;
    }
//file processing//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//creation of need//////////////////////////////////////////
        vector< vector<int> > need;

        int ti,tj,tv;

        temp.clear();



        printf("Needed resource:\n");
        for(int ti=0;ti<num_proc;ti++)
        {
            for(int tj=0;tj<num_res;tj++)
            {
                tv=max_res[ti][tj]-res_alloc[ti][tj];
                temp.push_back(tv);
                printf("%d ",tv);
            }
            printf("\n");
            need.push_back(temp);
            temp.clear();
        }

        printf("\n");
/////////////////////////////////////////////////////////////////////////////////////////////////
//creating arrival queue//////////////////////
        struct process p;
        priority_queue<process> arrival_queue;

        priority_queue<int, vector<int>, greater<int> > pending_queue;
        priority_queue<int, vector<int>, greater<int> > request_queue;

        queue<int>result;

        for(ti=0;ti<num_proc;ti++)
        {
            p.pid=process_id[ti];
            p.pavt=arrival_time[ti];

            arrival_queue.push(p);
        }

//////////////////////////////////////////////////////////////////////////////////////





                
    int demoi=0;       
    struct process new_process;
    int npid;

    int trpid;
    int flag_req_check=0;
    int flag_need_check=0;
    int deny_count=0;


    while(demoi<25)
    {

        
        if(result.size()==num_proc)
        {
            printf("size of result queue %d\n",result.size());

            while(!result.empty())
            {
                tv=result.front();
                result.pop();
                printf("%d ",tv );

                fprintf(fptr,"%d ", tv);

            }
            break;
        }

        if((deny_count>num_proc))
        {
            printf("NOT SAFE");

            fprintf(fptr,"%s", "NOT SAFE");
            break;
        }


        if(demoi>num_query)
        {
            if(result.size()!=num_proc)
            {
                printf("NOT SAFE");

                fprintf(fptr,"%s", "NOT SAFE");
                break;
            }
        }


        if(!arrival_queue.empty())
        {
            process new_process = arrival_queue.top();
            arrival_queue.pop();

            request_queue.push(new_process.pid);

            //printf("%d %d\n",new_process.pid,new_process.pavt );
            //break;
        }


        if(!request_queue.empty())
        {

                    trpid=request_queue.top();
                    request_queue.pop();

                    ///printf("%d\n",trpid);

                    flag_req_check=1;

                    for(ti=0;ti<num_res;ti++)
                    {
                        //printf("%d %d\n",query[trpid][ti+1],avail_res[ti]);

                        if(query[trpid][ti+1]>avail_res[ti])
                        {
                           flag_req_check=0; 
                        }

                    }

                    if(flag_req_check==1)
                    {
                        printf("GRANT :%d \n",trpid);
                        // fprintf(fptr,"GRANT :%d\n", trpid);
                        fprintf(fptr,"%s \n", "GREANT");
                        for(ti=0;ti<num_res;ti++)
                        {
                            //printf("%d %d\n",need[trpid][ti],query[trpid][ti+1]);
                            tv=need[trpid][ti]-query[trpid][ti+1];
                            need[trpid][ti]=tv;

                            
                        }

                        flag_need_check=1;

                        for(ti=0;ti<num_res;ti++)
                        {
                            if(need[trpid][ti]!=0)
                            {
                                 flag_need_check=0; 
                            }

                           // printf("%d ",need[trpid][ti]);
                        }



                        if(flag_need_check==1)
                        {
                            result.push(trpid);

                            for(ti=0;ti<num_res;ti++)
                            {
                                tv=avail_res[ti]+res_alloc[trpid][ti];
                                avail_res[ti]=tv;
                                
                                //printf("%d %d\n",res_alloc[trpid][ti],avail_res[ti]);

                            
                            }
                            //printf("\n");

                            //removing request from pending queue


                            if((arrival_queue.empty())||(result.size()!=num_proc))
                            {
                                while(!pending_queue.empty())
                                {
                                    tv=pending_queue.top();
                                    pending_queue.pop();
                                    request_queue.push(tv);
                                 }
                            }

                            

                        }

                      //  printf("\n%d \n",flag_need_check );





                    }
                    else
                    {
                        pending_queue.push(trpid);
                        printf("DENY\n");
                        //fprintf(fptr,"DENY :%d\n", trpid);
                        fprintf(fptr,"%s \n", "DENY");
                        deny_count++;
                        //printf("deny_count %d\n",deny_count );
                        
                    }

                    printf("\n");


                    continue;


        }




       // if(demoi==20)
       // printf("before demoi\n");
        demoi++;
    }

    fclose(fptr);
    printf("\n");
    return 0;
    
}














