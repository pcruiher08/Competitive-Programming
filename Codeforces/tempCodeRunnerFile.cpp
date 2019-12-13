        if(cuenta<nullsIndexes.size() && nullsIndexes[cuenta]-i<=k){
            k -= nullsIndexes[cuenta]-i;
            cuenta++;
            cout<<0;
        }else{
            cout<<1;
        }