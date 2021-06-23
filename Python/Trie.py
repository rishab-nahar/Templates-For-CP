###standard trie



class trie_node():
    def __init__(self,ch="root",parent=None):
        self.ch=ch
        self.children={}
        self.count=0
        self.parent=parent
        self.n_c_p=0
    def add(self,string):
        curr=self
        n=len(string)
        for i in range(n):
            curr.n_c_p+=1
            if string[i] in curr.children:
                curr=curr.children[string[i]]
            else:
                curr.children[string[i]]=trie_node(string[i],curr)
                curr = curr.children[string[i]]
        curr.count+=1
    def search(self,string):
        curr=self
        n=len(string)
        for i in range(n):
            if string[i] in curr.children:
                curr=curr.children[string[i]]
            else:
                return False
        if curr.count>0:
            return curr
        else:
            return False

    def starts_with(self,string):
        curr = self
        n = len(string)
        for i in range(n):
            if string[i] in curr.children:
                curr = curr.children[string[i]]
            else:
                return False
        return curr

    def delete(self,string):
        curr=self
        n=len(string)
        if self.search(string):
            for i in range(n):
                curr.n_c_p-=1
                curr=curr.children[string[i]]
            if curr.count>0:
                curr.count-=1
                while curr.count==0 and len(curr.children)==0 and curr.ch!="root":
                    k=curr.ch
                    curr= curr.parent
                    del curr.children[k]
                return True
        else:
            return False

    def pswcp_util(self,word):
        temp=[]
        for i in range(self.count):
            temp.append(word+self.ch)
        for i in self.children.keys():
            temp+=self.children[i].pswcp_util(word+self.ch)
        return temp



    def print_str_with_comm_prefix(self,string):
        k=self.starts_with(string)
        if  k:
            ar=[]
            for i in k.children.keys():
                ar+=k.children[i].pswcp_util(string)
            return ar
        else:
            return False

