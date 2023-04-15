import React from 'react';
import { Pressable, StyleSheet, Text, View } from 'react-native';

export default function CustomButton({onPress, label, bgColor = '#000'}:any) {
    return (        
        <Pressable onPress={onPress}>
            <View style={[styles.container, {backgroundColor: bgColor}]}>
                <Text>
                    {label}
                </Text>
            </View>
        </Pressable>
    )
}

const styles = StyleSheet.create({
    container: {
        padding: 10,
        borderRadius: 5,
    }
})