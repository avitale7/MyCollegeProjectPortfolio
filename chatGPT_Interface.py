import json, requests, maskpass #pip install maskpass
import tkinter as tk

#The send button runs this function
def openai_send():
    #gets the promt and prepares to send it to chatgpt 
    json_data['messages'][0]['content'] = interface_input.get()
    #gets the responce from chatgpt using the prompt and api key
    response = requests.post('https://api.openai.com/v1/chat/completions', headers=headers, json=json_data)
    #take only the message from chatgpt without all the behind the scenes information
    OpenAI_Data = json.loads(response.text) 
    if not 'error' in OpenAI_Data: 
        message = OpenAI_Data['choices'][0]['message']['content']
    else:
        print("Response error\n", OpenAI_Data, "\n")
        message = OpenAI_Data['error']['message']
    #sets the label to the message without getting rid of the previous message
    interface_output.set( interface_output.get() + '\n' + message )
    return

#the clear button runs this function
def clear_output():
    #sets the label to nothing
    interface_output.set("")
    return

#the tinkter interface and settings
interface_window = tk.Tk()
interface_window.geometry("1024x576")
interface_window.title("ChatGPT")
interface_window.config(bg="black")

#the variables for changing the texts of input and output while the interface is active
interface_output = tk.StringVar()
interface_input = tk.StringVar()

#applies a white background frame that stores the label, entry, and buttons
interface_frame_main = tk.Frame(interface_window, width = 1016, height = 568)
interface_frame_main.grid(column=0, row=0, padx=4, pady=4)

#the lable and position of where chatGPTs message will appear
interface_output_text = tk.Label(master=interface_frame_main, textvariable=interface_output, wraplength = int(1016*(3/4)), width = 128, height = 32)
interface_output_text.place(x=32, y=-32)

#the entry and position of where you will send chat gpt a prompt
interface_input_text = tk.Entry(master=interface_frame_main, textvariable=interface_input, width = 64) #I don't understand the width scaling of Entries
interface_input_text.place(x=int(1016/2 - 192),y=int(576*(8/9)))

#the send button to send the prompt to chatgpt
interface_button_enter = tk.Button(master=interface_frame_main, text="Send Message", borderwidth=1, command=openai_send, bg="light green")
interface_button_enter.place(x=int(1016/2 + 216),y=int(576*(8/9)))

#the clear button to clear the output of chatgpt
interface_button_clear = tk.Button(master=interface_frame_main, text="Clear", borderwidth=1, command=clear_output, bg="red")
interface_button_clear.place(x=int(1016/2 - 256),y=int(576*(8/9)))

#the apikey you are using to interact with chatgpt
#this requires you send your api key in the terminal before the interface launches 
API_KEY = maskpass.askpass(prompt="Password: ", mask="*").strip() #input("Password: ").strip()

#the variable that stores the prompt being sent to chatgpt   
user = "" #input("Message ChatGPT: ").strip() #console input

#the headers dictionary given by chatgpt in curl converted to python
headers = {
    'Content-Type': 'application/json',
    'Authorization': 'Bearer ' + API_KEY,
}

#the json data dictionary given by chatgpt in curl converted to python
json_data = {
    'model': 'gpt-3.5-turbo',
    'messages': [
        {
            'role': 'user',
            'content': user,
        },
    ],
    'temperature': 0.7,
}

'''
#the request given by chatgpt in curl converted to python
response = requests.post('https://api.openai.com/v1/chat/completions', headers=headers, json=json_data)
return_message = json.loads(response.text)['choices'][0]['message']['content']
print(return_message)
'''
#creates the window
tk.mainloop()