import re
import ply.lex as lex
import ply.yacc as yacc
 
tokens = ('LETTERA', 'LETTERB' )
 
t_ignore = r' '

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

t_LETTERA = r'[a]'
t_LETTERB = r'[b]'

lexer = lex.lex()
 
start = 'exec'

def p_exec(p):
    '''
    exec : R
    '''

def p_empty(p):
    'empty :'
    pass

def p_R(p):
    ''' 
    R : LETTERA LETTERA R LETTERB
      | LETTERA R LETTERB R LETTERA
      | LETTERB R LETTERA LETTERA
      | empty
    ''' 
    print(p)

parser = yacc.yacc()
 

## Test it
s = "aab"
if(yacc.parse(s, tracking = True) == 'All good'):
    print("Correct syntax.")
else:
    print("Syntax error")