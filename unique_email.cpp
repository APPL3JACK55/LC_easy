#include <vector>
#include <string>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
        vector<string> sent;
        for (int i = 0; i<emails.size(); i++){
            //check if email is valid
            //parse local name and domain name by looking for @
            int andPercent = emails[i].find("@");
            if(andPercent){
                //check andPercent in beginning
                //check andPercent at end
                if(andPercent == emails[i].size()-1){continue;}
                //check domain name rules
                string domain = emails[i].substr(andPercent, emails[i].size()-andPercent);
                int domainDot = domain.find(".");
                //is it seperated by a dot
                if(domainDot >= 0){
                    string local = emails[i].substr(0, andPercent);
                    
                    //check local name rules
                    int localPlus = local.find("+");
                    if(localPlus >= 0){
                        local = local.substr(0, localPlus);
                    }
                    
                    int localDot = local.find(".");
                    while(localDot >= 0){
                        //erase dot
                        local = local.erase(localDot, 1);
                        localDot = local.find(".");
                        
                    }
                    bool found = false;
                    for(int j = 0; j < sent.size(); j++){
                        if(sent[j].find(local+domain) != -1){
                            found = true;
                        }
                    }
                    
                    if(!found){
                        sent.push_back(local+domain);
                    }
                }
            
            }
        }
        return sent.size();
    }


int main()
{
    
    vector<string> emails = {"j+d.j.b.k.xr.mmp@rn.qyy.com","j+yt+w.on.k.r+i.l@rn.qyy.com","j+i.t.b.o.x.l.s.a.z@rn.qyy.com","j+wteuapmm.y@rn.qyy.com","q.z.y.znvz.d+l+p@kyf.com","np.e.x+u.a+mbv+j@uadsua.rqda.com","np.e.x+e.f.n.f.r.c@uadsua.rqda.com","pdiykt.rh+cc@ta.bxx.com","j+aqlxgyy+b.k@rn.qyy.com","j+a.hm.y.t.j.d+qq@rn.qyy.com","k.i.j.hy.pe.n+ea@xfeslns.com","j+h.v.w.b+x+h.e.n.r@rn.qyy.com","j+m+j.k.o.jl.vv+r@rn.qyy.com","k.i.j.hy.pe.n+l+i@xfeslns.com","k.i.j.hy.pe.n+nh@xfeslns.com","j+akd.xb.xx+c.e@rn.qyy.com","j+a.j.u+e.s.p+w.x.x@rn.qyy.com"};

    int result = numUniqueEmails(emails);
    
    
    return 0;
}
